//Binary Search implementation
#include<iostream>

int BinarySearch(int arr[], int s, int e, int k)
{
  if(s<=e)
  {
    int m = (s+e)/2;//find out the middle index
    if(k<arr[m])
    {
      return BinarySearch(arr, s, m-1, k);
    }
    else if(k>arr[m])
    {
      return BinarySearch(arr, m+1, e, k);
    }
    else
    {
      return m;
    }
  }
  return -1;
}

int main()
{
  int arr[] = {3,6,7,12,15,18}; //assuming arraay is in ascending order
  int N = sizeof(arr)/sizeof(arr[0]);
  int k =18;
  
  //sea1rching for the element k
  int index = BinarySearch(arr,0, N-1,k);
  if(index!=-1)
    std::cout<<"Element Found at index "<<index;
  else
    std::cout<<"Element not found";;
  
  return 0;
}