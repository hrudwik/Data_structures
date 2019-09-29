// C/C++ program to remove all adjacent duplicates from a string 
#include<bits/stdc++.h>

using namespace std;

bool doesNoNumMatch(int a, int b)
{
  unordered_set<int> s;
  while(a)
  {
    int n = a%10;
    s.insert(n);
    a = a/10;
  }

  while(b)
  {
    int n = b%10;
    if(s.find(n)!=s.end())
      return false;
    b = b/10;
  }
  return true;
}

int countSpecificNumsInRange(int l, int r, int q)
{
  int count = 0;

  for(int i=l;i<=r;i++)
  {
    if(doesNoNumMatch(i,i*q))
      count++;
  }

  return count;
}

// Driver program to test above functions 
int main() 
{ 
  //[l,r]   q
	//int l = 10,r= 12,q=2;
  int l = 5,r= 15,q=2;

  cout<<countSpecificNumsInRange(l,r,q)<<endl;

	return 0; 
} 