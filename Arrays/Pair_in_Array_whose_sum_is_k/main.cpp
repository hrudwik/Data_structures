#include<bits/stdc++.h>
using namespace std;

void findAndPrintSuchPairs(int arr[],int N,int k)
{
  //stores the parsed records in hash table
  unordered_set<int> s;

  for(int i=0;i<N;i++)
  {
    if( s.find(k-arr[i]) != s.end())
    {
      cout<<"("<<min(arr[i], k-arr[i])<<", "<<max(arr[i], k-arr[i])<<")"<<endl;
    }
    else
    {
      s.insert(arr[i]);
    }
  }
}

int main()
{
  int arr[] = {1, 4, 12, 6, 10, -8};
  int N = sizeof(arr)/sizeof(arr[0]);
  int k = 16;  //required pair sum
  findAndPrintSuchPairs(arr,N,k);

  return 0;
}