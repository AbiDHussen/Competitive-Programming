#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int d[N];//store all the numbers divisor count upto N
int main()//time complexity = nlog(n)
{   
    int n=100;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            d[j]++;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}