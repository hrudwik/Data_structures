#include<bits/stdc++.h>
using namespace std;

int findMinInArray(int arr[], int N)
{
  int min = arr[0];
  for(int i=1;i<N;i++)
  {
    if(arr[i]<min)
    {
      min = arr[i];
    }
  }

  return min;
}

bool isPositiveNumberExists(int arr[], int N)
{
  for(int i=0;i<N;i++)
  {
    if(arr[i]>0)
    {
      return true;
    }
  }
  return false;
}


long long CalculateMaxSumAndPrintMaxSumSubArray(int arr[], int N)
{
  long long max_sum = INT_MIN;
  int fin_start_index = -1, fin_end_index = -1;
  if(N>=1)
  {
    if(isPositiveNumberExists(arr,N))
    {
      long long cur_sum = 0;
      int start_index = 0;
      //take it to first positive integer
      for(int i=0;i<N;i++)
      {
        if(arr[i]>0)
        {
          start_index = i;
          break;
        }
      }
      for(int i=start_index;i<N;i++)
      {
        cur_sum += arr[i];
        if(arr[i]>cur_sum)
        {
          cur_sum = arr[i];
          start_index = i;
          if(cur_sum>max_sum)
          {
            max_sum = cur_sum;
            fin_start_index = start_index;
            fin_end_index = i;
          }
        }
        else if(cur_sum<0)
        {
          start_index = i+1;
        }
        else if(cur_sum>max_sum)
        {
          max_sum = cur_sum;
          fin_start_index = start_index;
          fin_end_index = i;
        }
      }
    }
    else
    {
      max_sum = findMinInArray(arr, N);
    }
  }
  cout<<"start index: "<<fin_start_index<<endl;
  cout<<"end index: "<<fin_end_index<<endl;
  return max_sum;
}

int main()
{
  //int arr[] = {-2, -3, 4, -1, -2, 1, 5,-3};
  int arr[] = {-2, 1, 4, -7, 12, -13, 5, 7};
  
  int N = sizeof(arr)/sizeof(arr[0]);
  long long res = CalculateMaxSumAndPrintMaxSumSubArray(arr,N);
  cout<<"Max Sum ="<<res;
  
  return 0;
}