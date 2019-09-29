#include<bits/stdc++.h>

using namespace std;

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

int main()
{
  int n=13;
  if(IsPrime(n))
    cout<<"Number is prime";
  else
    cout<<"Number is not a prime";
  

  return 0;
}