// C/C++ Solution of Share Purchase problem
#include<bits/stdc++.h>

using namespace std;

//This function is jjust for debuggin purpose
int findMaximalCommanlity(string str)
{
  if(str.size()<2)
    return 0;
  
  int maxMatch = 0, match = 0, n =str.size();
  int Lt[26] = {0};
  int Rt[26] = {0};
  
  //for Lt ---  str[0]
  Lt[str[0]-'a']++;
  //for Rt ---  str[1]:str[n-1]
  for(int i=n-1;i>=1;i--)
  {
    Rt[str[i]-'a']++;
    if(Lt[str[i]-'a'] == 1)
      {
        match = 1;
        maxMatch = 1;
      }
  }

  //now slide Lt window right and Rt window right
  for(int i=1;i<=n-2;i++)
  {
    //cout<<"St "<<i<<" "<<match<<" "<<Lt[str[i]-'a']<<" "<<Rt[str[i]-'a']<<endl;
    if(Lt[str[i]-'a'] == Rt[str[i]-'a'])
    {
      match--;
    }
    else if(Lt[str[i]-'a'] > Rt[str[i]-'a'])
    {
      match--;
    }
    else
    {
      if( !(Lt[str[i]-'a'] ==0 && Rt[str[i]-'a']==1) )
      {
        match++;
        if(match>maxMatch)
          maxMatch = match;
      }
    }
    Lt[str[i]-'a']++;
    Rt[str[i]-'a']--;
    //cout<<"Ed "<<i<<" "<<match<<" "<<Lt[str[i]-'a']<<" "<<Rt[str[i]-'a']<<endl;
  }

  return maxMatch;  
}

int main() 
{ 
  //string str = "abcdecdefg";
  string str = "aabbbbaa";
  cout<<findMaximalCommanlity(str);
	return 0; 
} 