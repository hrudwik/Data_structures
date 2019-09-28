// C/C++ program to remove all adjacent duplicates from a string 
#include <iostream> 
#include <string.h> 
#include<stack>

using namespace std; 

string print(stack<char> s)
    {
        string str;
        while (s.size()) {
            str += s.top();
            s.pop();
        }
        return str;
    }

string removeDuplicates(string S) 
{
    stack<char> s;
    int len = S.size();
    for (int i = len - 1; i >= 0; i--) {
        s.push(S[i]);
        while(i-1>=0 && s.size() && s.top() == S[i-1])
        {
            s.pop();i--;
        }
    }
    
    //putting stack data into string
    string str = "";
    while(s.size())
    {
        str += s.top();
        s.pop();
    }

    return str;    
}

// Driver program to test above functions 
int main() 
{ 
	string str1 = "geeksforgeeg"; 
	cout << removeDuplicates(str1) << endl; 

	return 0; 
} 
