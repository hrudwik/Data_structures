//================= Legacy Code ====================

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include <thread>
#include <type_traits>
#include <mutex>
using namespace std;

// mutex to lock critical region
std::mutex mylock;

template<typename NumType = float>
void RenderSphereOnScreen(const NumType * const _coords)
{
	//Some time consuming Graphics stuff
	// No need To implement it
	mylock.lock();
	std::cout << _coords[0] << " " << _coords[1] << " " << _coords[2] << std::endl;
	mylock.unlock();

}

/**
*Modify templated SphereRenderTask class in such a way that it will accept only Integers or Real numbers.
* accepted :   SphereRenderTask<int>/SphereRenderTask<float>/SphereRenderTask<double>
* error : SphereRenderTask<anyother_type>
*/
template<typename NumType = float>
class SphereRenderTask
{
	NumType  _coords[3];
	//This static_assert will only accept  int, float and double
	static_assert(std::is_same<NumType, int>::value || std::is_same<NumType, double>::value || std::is_same<NumType, float>::value,
		"some meaningful error message");
public:
	SphereRenderTask(const NumType& x, const NumType& y, const NumType& z) : _coords{ x, y, z } {}

	void operator()() const
	{
		RenderSphereOnScreen(_coords);
	}
};

void SplitLength(std::ifstream& inputfile, int& len)
{
	int x, y, z;

	while (inputfile >> x >> y >> z)
	{
		++len;
	}
}

void readFile(const char* const inputFilePath, std::vector<SphereRenderTask<int>*>& taskList, int start_line, int end_line)
{
	std::ifstream inputfile;
	//prepare inputfile to throw if failbit gets set
	std::ios_base::iostate exceptionMask = inputfile.exceptions() | std::ios::failbit;
	inputfile.exceptions(exceptionMask);

	try {
		inputfile.open(inputFilePath);

		int x, y, z;
		string temp = "";
		int cur = 0;
		while (!inputfile.eof() && !inputfile.fail() && cur != end_line)
		{
			if (cur >= start_line && cur <= end_line)
			{
				mylock.lock();
				inputfile >> x >> y >> z;
				taskList.push_back(new SphereRenderTask<int>(x, y, z));
				mylock.unlock();
			}
			else
			{
				getline(inputfile, temp);
			}

			cur++;
		}

		inputfile.close();
	}
	catch (std::ios_base::failure& e) {
		if (e.code() == std::make_error_condition(std::io_errc::stream))
			std::cerr << "Stream error!\n";
		else
			std::cerr << "Unknown failure opening file.\n";
	}
	catch (...) {
		std::cerr << "Generic exception caught\n";
	}
}

void PrintInThreadMode(std::vector<SphereRenderTask<int>*> taskList, int size, bool trigger)
{
	if (trigger == 0)
	{
		for (int i = 0; i < size; i += 2)
		{
			(*taskList[i])();
		}
	}
	else
	{
		for (int i = 1; i < size; i += 2)
		{
			(*taskList[i])();
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

	std::ifstream inputfile;

	try {
		inputfile.open(inputFilePath);
		if (!inputfile.fail())
		{
			int th1 = 0, th2 = 0;
			SplitLength(inputfile, th2);
			th1 = th2 / 2;
			cout << "th1: " << th1 << endl;
			cout << "th2: " << th2 << endl;
			inputfile.close();

			//readFile(inputFilePath, taskList, 0, th1);
			std::thread th_1(readFile, inputFilePath, std::ref(taskList), 0, th1);
			std::thread th_2(readFile, inputFilePath, std::ref(taskList), th1, th2);

			th_1.join();
			th_2.join();

			int size = taskList.size();
			//PrintInThreadMode(taskList, size, 0);
			std::thread th_3(PrintInThreadMode, taskList, size, 0);
			std::thread th_4(PrintInThreadMode, taskList, size, 1);
			th_3.join();
			th_4.join();
		}
		cout << "Fin" << endl;
	}
	catch (std::ios_base::failure& e) {
		if (e.code() == std::make_error_condition(std::io_errc::stream))
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
	if (argc < 1)
	{
		std::cerr << "Bad Input" << std::endl;
		return EXIT_FAILURE;
	}
	//argv[1] := Pass the enclosed input "sphere.txt" file's path.
	StartRendering(argv[1]);
	cout << "Main Fin" << endl;

	return 0;
}
