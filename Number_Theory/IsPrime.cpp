#include <bits/stdc++.h>
using namespace std;
bool isitPrime(int n)//time complexity=O(sqrt(n))
{
  if(n==1)return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)return false;
  }
  return true;
}
int main()
{   
    cout<<isitPrime(7)<<endl;
    return 0;
}