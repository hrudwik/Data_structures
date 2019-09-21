#include<bits/stdc++.h>
using namespace std;

int PossiblePairs(int n)
{
  return n*(n-1)/2;
}

int CountSuchPairs(int arr[],int N)
{
  int count = 0;
  count += PossiblePairs(N);

  unordered_map<int,int> freq;
  for(int i=0; i<N; i++)
  {
    freq[arr[i]]++;
  }

  for( auto x : freq )
  {
    int v = x.second;
    count -= PossiblePairs(v);
  }
  return count;
}

int main()
{
  int arr[] = {1, 1, 4, 9};
  //int arr[] = {2, 4, 5, 2, 5, 7, 2, 8};
  int N = sizeof(arr)/sizeof(arr[0]);
  cout<<CountSuchPairs(arr,N);

  return 0;
}