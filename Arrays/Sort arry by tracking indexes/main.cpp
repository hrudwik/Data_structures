#include <bits/stdc++.h> 
using namespace std; 
  
void sortArr(int arr[], int n) 
{
  vector<pair<int, int> > vp; 

  // Inserting element in pair vector 
  // to keep track of previous ind/exes
  for (int i = 0; i < n; ++i) { 
      vp.push_back(make_pair(arr[i], i)); 
  } 

  // Sorting pair vector 
  sort(vp.begin(), vp.end()); 

  // Displaying sorted element 
  // with previous indexes 
  // corresponding to each element 
  cout << "Element\t"
        << "index" << endl; 
  for (int i = 0; i < vp.size(); i++) 
  { 
      cout << vp[i].first << "\t"
            << vp[i].second << endl; 
  } 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 2, 5, 3, 7, 1 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    sortArr(arr, n); 
  
    return 0; 
} 