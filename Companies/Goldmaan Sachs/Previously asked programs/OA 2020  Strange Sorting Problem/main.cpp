#include <bits/stdc++.h> 
using namespace std; 

vector<pair<int, int> > sortArr(int arr[], int n) 
{
  vector<pair<int, int> > vp; 

  for (int i = 0; i < n; ++i) { 
      vp.push_back(make_pair(arr[i], i)); 
  } 

  sort(vp.begin(), vp.end()); 
  return vp;
}

//reverse number
int reversDigits(int num) 
{ 
    int rev_num = 0; 
    while(num > 0) 
    { 
        rev_num = rev_num*10 + num%10; 
        num = num/10; 
    } 
    return rev_num; 
}

int transformNumAsPerMapping(vector<pair<int, int>> mapVec, int n)
{
  int res = 0;

  while(n)
  {
    int k = mapVec[n%10].second;
    res = res*10 + k;
    n=n/10;
  }
  res = reversDigits(res);
  return res;
}

bool compare_as_pair (pair<int, string> i,pair<int, string> j)
{
  return ( i.first < j.first );
}

vector<string> strangeSort(int mapping[], vector<string> nums, int m)
{
  vector<pair<int, int>> mapVec = sortArr(mapping, m);

  int n = nums.size();
  vector<pair<int, string> > resVec;
  for(int i=0; i<n;i++)
  {
    int num = stoi(nums[i]);
    resVec.push_back(make_pair(transformNumAsPerMapping(mapVec, num), nums[i]));
  }

  stable_sort(resVec.begin(), resVec.end(), compare_as_pair);
  
  vector<string> finVec;
  for(int i=0; i< resVec.size(); i++)
  {
    finVec.push_back(resVec[i].second);
  }
  return finVec;
}

void printVec(vector<string> finVec)
{
  for(int i=0; i< finVec.size(); i++)
    {
      cout<<finVec[i]<<" ";
    }
}

int main() 
{ 
     //int mapping[] = { 2, 1, 4, 8, 6, 3, 0, 9, 7, 5 };
     //vector<string> nums = { "12", "02", "4", "023", "65", "83", "224", "50"};
    int mapping[] = { 3, 5, 4, 6, 2, 7, 9, 8, 0, 1 }; //fixed size 10
    vector<string> nums = { "990", "332", "32"};
    int m = sizeof(mapping) / sizeof(mapping[0]);

    vector<string> finVec;
    finVec = strangeSort(mapping, nums, m);

    printVec(finVec);
    
    return 0; 
} 