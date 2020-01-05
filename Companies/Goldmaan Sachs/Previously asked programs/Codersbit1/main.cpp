  // CPP code to count the singleton sub-graphs 
// in a disconnected graph 
#include <bits/stdc++.h> 
using namespace std; 

int minmm(int a, int b)
{
  if(a<b)
    return a;
  return b;
}

int dp(vector<int> &A, vector<int> &B, int s, int e, int C)
{
  int len = C+1;
  cout<<"s: "<<s<<" "<<"e: "<<e<<endl;

  if(s>e)
    return 0;
  if(s==e)
    return B[0];

  for(int i=s; i<=s; i++)
  {
    for(int j=i+1; j<=e; j++)
    {
      cout<<"i: "<<i<<" "<<"j: "<<j<<endl;
      int p_len = A[j] - A[i], b_index = -1;
      //cout<<"p_len: "<<p_len<<" "<<"b_index: "<<b_index<<endl;
        for(int k=0; k<B.size(); k++)
        {
          if(B[k]>=p_len)
          {
            b_index = k;
            break;
          }
        }
      //cout<<"p_len: "<<p_len<<" "<<"b_index: "<<b_index<<endl;
        if(b_index != -1)
        {
          len = minmm(len, B[b_index] + dp(A, B, j+1, A.size()-1, C) );
          cout<<"m_len "<<s<<" "<<e<<" "<<i<<" "<<j<<" "<<B[b_index]<<" "<<len<<endl;
        }
        else
        {
          if(i+1==j)
          {
            len = B[0] + dp(A, B, j, A.size()-1, C) ;
            cout<<"n_len: "<<s<<" "<<e<<" "<<len<<" "<<len<<endl;
          }
          break;
        }
    }
  }
  cout<<"s: "<<s<<" "<<"e: "<<e<<" len: "<<len<<endl;
  return len;
}

int solve(vector<int> &A, vector<int> &B, int C)
{
  int res = 0;

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  res = dp(A, B, 0, A.size()-1, C);
  return res;
}

int main() 
{ 
  //  vector<int> A = {2, 3, 5, 8, 11, 15};
	//  vector<int> B ={2, 3};
  //vector<int> A = {2, 4, 18};
	//vector<int> B ={2, 4, 6, 7};
  // vector<int> A = {3, 1, 25};
	// vector<int> B ={2, 4, 5};
  vector<int> A = {1, 5, 10, 20, 25, 30, 35, 38};
	vector<int> B ={2, 5, 8, 10, 44};

  int C = 398, ans = 0;
  //printVec(res);
  ans = solve(A, B, C);
  cout<<"ans: "<<ans;
  return 0;
} 