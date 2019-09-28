#include <bits/stdc++.h>
#include <vector> 

using namespace std;

//Testing purpose
void printVec(vector<char> s)
{
  for(int i=0;i<s.size();i++)
  {
    cout<<s[i];
  }
  cout<<endl;
}

void reverseString(vector<char>& s)
{
  int st = 0, ed = s.size()-1;
  while(st<ed)
  {
    char tmp = s[st];
    s[st] = s[ed];
    s[ed] = tmp;
    st++;
    ed--;
  }
}

int main()
{
    vector<char> vec = {'a','z','x','x','z','y'};//("azxxzy");
    reverseString(vec);
    printVec(vec);
    return 0;
}