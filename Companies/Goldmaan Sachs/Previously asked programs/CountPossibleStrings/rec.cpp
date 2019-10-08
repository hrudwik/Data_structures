// C/C++ program to remove all adjacent duplicates from a string 
#include<bits/stdc++.h>

using namespace std;

void printVec(vector<int> vec)
{
  for(int i=0;i<vec.size();i++)
  {
    cout<<vec[i]<<" ";
  }
  cout<<endl;
}

int countPossibilities(string str, int s, int e, vector<int>& DP)
{
  if(s>e)
    return 0;
  if(s==e)
    return 1;

  if(DP[s+1] != 0)
    return DP[s+1];
  DP[s+1] += countPossibilities(str, s+1, e, DP);
  //count += countPossibilities(str, s+2, e);
  if(s+2<=e)
  {
    if( str[s+1] == '0' || str[s+1] == '1' || (str[s+1] == '2' && (str[s+2] == '0' ||
        str[s+2] == '1' ||str[s+2] == '2' || str[s+2] == '3' || str[s+2] == '4' || str[s+2] == '5')) )
    DP[s+1] += countPossibilities(str, s+2, e, DP);
  }

  

  return DP[s+1];
}

// Driver program to test above functions 
int main()
{ 
  string str= "2112";
  vector<int> DP(str.size()+2, 0);
  cout<< countPossibilities(str, str.size()-1, DP) <<endl;
  str= "71720322810";
  DP(str.size()+2, 0);
  cout<< countPossibilities(str, str.size()-1, DP) <<endl;
  str= "212121";
  DP(str.size()+2, 0);
  cout<< countPossibilities(str, str.size()) <<endl;
  str= "121711";
  DP(str.size()+2, 0);
  cout<< countPossibilities(str, str.size()) <<endl;
  //vector<int> DP(str.size()+2, 0);
  
  //printVec(DP);
  //cout<< countPossibilities(str, -1, str.size()-1, DP) <<endl;

	return 0; 
}