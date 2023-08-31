#include <bits/stdc++.h>
using namespace std;
//time complexity = O(sqrt(n))
int main()
{  
    int n;
    cin>>n;
    vector<int>prime;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                prime.push_back(i);
                n/=i;
            }
        }
    }
    if(n>1)prime.push_back(n);
    for(auto it : prime)cout<<it<<" "; 
    return 0;
}