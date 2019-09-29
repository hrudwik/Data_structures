// C/C++ Solution of Share Purchase problem
#include<bits/stdc++.h>

using namespace std;

//This function is jjust for debuggin purpose
void printVector(vector<pair<int,int>> v)
{
  if(v.size()<1)
    return;
  cout<<"[";
    for(int i=0;i<v.size();i++)
        cout<<v[i].first<<" ";
    cout<<"]";
    cout<<endl;
}

int findTheRank(vector<vector<int>>& matrix, int rank) 
{
  if(matrix.size()<1)
    return -1;
  
  int r =matrix.size(), c= matrix[0].size(), marks=0;
  
  //To maintain index after sorting we are considering pair in vector 
  vector<pair<int,int>> studMarks;

  for(int i=0; i<r; i++)
  {
    marks = 0;
    for(int j=0; j<c; j++)
    {
      marks += matrix[i][j];
    }
    studMarks.push_back(make_pair(marks, i));
  }
  //printVector(studMarks);

  //we are using stable sort(which uses merge sort internally) to ensure no reordering happens
  stable_sort(studMarks.begin(),studMarks.end());
  //printVector(studMarks);
  return studMarks[rank-1].second+1; //student indexing is from 1
}

int main() 
{ 
  //vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  vector<vector<int>> matrix = {{79,89,15},{71,96,88},{85,89,92},{71,96,88},{71,96,99}, {71,96,88}};
  int rank = 3;
  cout<<findTheRank(matrix, rank);

	return 0; 
} 