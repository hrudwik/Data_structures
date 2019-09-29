// C/C++ Solution of Share Purchase problem
#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int> v)
{
  if(v.size()<1)
    return;
  cout<<"[";
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<"]";
}

bool IsPrime(int n)
{
  if(n<=1)
    return false;
  if(n<=3)
    return true;

  //Every prime number will be of form 6x+1 or6x-1 {where x is any natural number}
  if( (n-1)%6 !=0 && (n+1)%6!=0 )
    return false;
  if(n%2==0 || n%3==0)
    return false;
  
  for(int i=5;i*i<=n;i+=6)
    if(n%i==0 || n%(i+2)==0)
      return false;

  return true;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    vector<int> retVec;
    if(matrix.size() < 1)
        return retVec;
    int r1=0, r2=matrix.size()-1, c1=0, c2=matrix[0].size()-1;
    while(r1<=r2 && c1<=c2)
    {
        //cout<<r1<<" "<<r2<<" "<<c1<<" "<<c2<<endl;
        for(int j=c1;j<=c2;j++)
            if(IsPrime(matrix[r1][j]))
            retVec.push_back(matrix[r1][j]);
        for(int i=r1+1;i<=r2;i++)
            if(IsPrime(matrix[i][c2]))
            retVec.push_back(matrix[i][c2]);
        if(r1!=r2)
        for(int j=c2-1;j>=c1;j--)
            if(IsPrime(matrix[r2][j]))
            retVec.push_back(matrix[r2][j]);
        if(c1!=c2)
        for(int i=r2-1;i>r1;i--)
            if(IsPrime(matrix[i][c1]))
            retVec.push_back(matrix[i][c1]);
        c1++; c2--; r1++; r2--;
    }
    return retVec;
}

// Driver program to test above functions 
int main() 
{ 
  vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  printVector(spiralOrder(matrix));

	return 0; 
} 