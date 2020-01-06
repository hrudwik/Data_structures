//================= Legacy Code ====================

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <pthread.h>
#include <type_traits>

using namespace std; 

template<typename NumType=float>
void RenderSphereOnScreen(const NumType* const _coords)
{
   //Some time consuming Graphics stuff
   // No need To implement it
   std::cout<<_coords[0]<<" "<<_coords[1]<<" "<<_coords[2]<<std::endl;

}

/**
*Modify templated SphereRenderTask class in such a way that it will accept only Integers or Real numbers.
* accepted :   SphereRenderTask<int>/SphereRenderTask<float>/SphereRenderTask<double>
* error : SphereRenderTask<anyother_type>
*/
template<typename NumType=float>
class SphereRenderTask
{
     NumType  _coords[3];
     //This static_assert will only accept  int, float and double
     static_assert(std::is_same<NumType, int>::value || std::is_same<NumType, double>::value || std::is_same<NumType, float>::value,
                "some meaningful error message");
     public:
     SphereRenderTask(const NumType& x, const NumType& y, const NumType& z): _coords{x, y, z}{}

     void operator()() const
     {
          RenderSphereOnScreen(_coords);
     }
};

void readFile(std::ifstream &inputfile, std::vector<SphereRenderTask<int>*> &taskList, int start_line, int end_line) 
{ 
    int x,y,z;
    string temp = "";
    int cur = 0;
    while (!inputfile.eof() && !inputfile.fail() && cur!=end_line)
    {
        if(cur>= start_line && cur <= end_line)
        {
            inputfile >> x >> y>> z;
            taskList.push_back(new SphereRenderTask<int>(x,y,z));
        }
        else
        {
            getline(inputfile, temp);
        }
        
        cur++;
    }
}

void SplitLength(std::ifstream &inputfile, int &th1, int&th2)
{
    string temp = "";
    while (!inputfile.eof() ) {
            std::cout<<"Current Pos: "<<inputfile.tellg()<<std::endl;
            getline(inputfile, temp);
            ++th1;
            ++th2;
            if( !inputfile.eof() )
            {
                getline(inputfile, temp);
                ++th2;
            }
        }
}

/**
* (1) Identify which part of the code can be improved through multithreading, you can use any multi-threading library.
* (2) Apart from Multithreading, there is one more issue in the code below, Identify and fix it.
* @return
*/
void StartRendering(const char* const inputFilePath)
{

    std::vector<SphereRenderTask<int>*> taskList;

    std::ifstream inputfile, inputfile2;
    //prepare inputfile to throw if failbit gets set
    std::ios_base::iostate exceptionMask = inputfile.exceptions() | std::ios::failbit;
    inputfile.exceptions(exceptionMask);
    inputfile2.exceptions(exceptionMask);

    try {
        inputfile.open(inputFilePath);
        
        int th1 = 0, th2 = 0;
        SplitLength(inputfile, th1, th2);
        cout<<"th1: "<<th1<<endl;
        cout<<"th2: "<<th2<<endl;
        inputfile.seekg(std::ios::beg);
        inputfile2.open(inputFilePath);

        pthread_t pth1;
        int rc;
        rc = pthread_create(&pth1, NULL, readFile, inputfile, taskList, 0, th1);
      
        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
        pthread_exit(NULL);
        //std::this_thread th1(readFile, inputfile, taskList, 0, th1);
        //std::thread th2(readFile, inputfile2, taskList, th1, th2);

        //th1.join(); 
        //th2.join(); 
        inputfile.close();
        inputfile2.close();

        for(std::vector<SphereRenderTask<int>*>::iterator iter=taskList.begin(); iter!=taskList.end(); ++iter)
        {
            (**iter)();
        }
    }
    catch (std::ios_base::failure& e) {
        if ( e.code() == std::make_error_condition(std::io_errc::stream) )
            std::cerr << "Stream error!\n"; 
        else
            std::cerr << "Unknown failure opening file.\n";
    }
    catch (...) {
        std::cerr << "Generic exception caught\n";
    }
}

int main(int argc, const char* argv[])
{
   //SphereRenderTask<char> *abc = new SphereRenderTask<char>(1,2,3);
   if(argc<1)
   {
       std::cerr<<"Bad Input"<<std::endl;
       return EXIT_FAILURE;
   }
   //argv[1] := Pass the enclosed input "sphere.txt" file's path.
   StartRendering(argv[1]);

 return 0;
}
