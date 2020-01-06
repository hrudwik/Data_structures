// C/C++ program to remove all adjacent duplicates from a string 
#include<bits/stdc++.h>

using namespace std;

bool isInRange(char a, char b)
{
    if( a == '0' || a == '1' || (a == '2' && (b >= '0' && b <= '5')) )
      return true;
    return false;
}

int countPossibilities(string str, int n)
{
  if(n == 0)
    return 0;
  else if(n==1)
    return 1;
  
  vector<int> DP(n+2, 0);

  DP[0] = 1;
  if(isInRange(str[0], str[1]))
    DP[1] = 2;
  else
    DP[1] = 1;
  

  for(int i=2; i<n; i++)
    {
      DP[i] += DP[i-1];
      if(isInRange(str[i-1], str[i]))
        DP[i] += DP[i-2];
        //cout<<i<<" "<<DP[i]<<endl;
    }
    

  return DP[n-1];
}

// Driver program to test above functions 
int main()
{ 
  string str= "2112";
  cout<< countPossibilities(str, str.size()) <<endl;
  str= "71720322810";
  cout<< countPossibilities(str, str.size()) <<endl;
  str= "212121";
  cout<< countPossibilities(str, str.size()) <<endl;
  str= "121711";
  cout<< countPossibilities(str, str.size()) <<endl;
  
  //printVec(DP);
  //cout<< countPossibilities(str, str.size()) <<endl;

	return 0; 
}