// C/C++ program to choose Adds efficiently
#include<bits/stdc++.h>

using namespace std;

int DP[100002];

int countPossibilities(vector<int> V, vector<vector<int>> Ads, int ms, int me)
{
  int count = 0;

  if(ms>me)
    return 0;
  if(DP[ms] !=0)
  {
    cout<<"Used\n";
    return DP[ms];
  }

  for(int i=0; i<Ads.size(); i++)
  {
    if(Ads[i][0]>=ms && Ads[i][1]<=me)
    {
      count = max( V[i] + countPossibilities(V, Ads, Ads[i][1]+5, me), count );
    }
  }
  DP[ms]=count;

  return count;
}

int main()
{ 
  int m=20;
  vector<int> V({6, 3, 9, 7, 10});
  vector<vector<int>> Ads(
    {
      {12, 13},
      {2, 3},
      {6, 9},
      {14, 17},
      {10, 12}
    }
  );
  //vector<int> V({3, 9, 10, 6, 7});
  /*vector<vector<int>> Ads(
    {
      {2, 3},
      {6, 9},
      {10, 12},
      {12, 13},
      {14, 17}
    }
  );*/
  //Assuming Ads in sorted order
  memset(DP, 0, 1e5+2);
  cout<<countPossibilities(V, Ads, 0, m); //0,m movie start n end time

	return 0; 
}