// time compexity=>O(1)
#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    double phi = (sqrt(5) + 1) / 2;
    return round(pow(phi, n) / sqrt(5));
}
int main()
{
    int n;
    cin>>n;
    cout << fib(n);
    return 0;
}