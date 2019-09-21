#include<bits/stdc++.h>
using namespace std;

int nc2(int n)
{
  if(n<2)
  return 0;
  return n*(n-1)/2;
}

int CountPairsWhichAreDivisibleByK(int arr[],int N,int k)
{
  int count = 0;
  int freq[k] = {0};

  for(int i=0; i<N;i++)
  {
    freq[arr[i]%k]++;
  }
  count += nc2(freq[0]);
  int s=1, e =k-1;
  while(s<e)
  {
    count += freq[s]*freq[e];
    s++;
    e--;
  }
  if(s==e)
  {
    count += nc2(freq[s]);
    cout<<count<<endl;
  }
  return count;
}

int main()
{
  int arr[] = {5, 9, 36, 74, 52, 31, 42};
  int N = sizeof(arr)/sizeof(arr[0]);
  int k = 3;  //divisible by k
  cout<<CountPairsWhichAreDivisibleByK(arr,N,k);

  return 0;
}