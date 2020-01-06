// C/C++ program to to find trapped rain water
#include<bits/stdc++.h>
using namespace std;

int trappedAmountOfRainWater(vector<int> V)
{
  int n = V.size();
  if(n<3)  //for upto 2 buildings rain water can't be trapped
    return 0;
  int s=0,e=n-1,leftMax = 0, rightMax = 0, totalWater = 0; 
  //leftMax is current leftmax from left tll element s
  //rightMax is current rightMax from right tll element e

  while(s<e)
  {
    if(V[s]<V[e])
    {
      if(V[s]>leftMax)
        leftMax = V[s];
      else
        totalWater += leftMax - V[s];
      s++;
    }
    else
    {
      if(V[e]>rightMax)
        rightMax = V[e];
      else
        totalWater += rightMax - V[e];
      e--;
    }
  }
  return totalWater;
}

int main()
{ 
  int m=20;
  //vector<int> V({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
  vector<int> V({0, 5, 2, 5, 1, 3});
  cout<<trappedAmountOfRainWater(V);

	return 0; 
}