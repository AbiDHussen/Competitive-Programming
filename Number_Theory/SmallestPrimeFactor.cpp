#include <bits/stdc++.h>
using namespace std;
bool isitPrime(int n) // time complexity=O(sqrt(n))
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()//find smallest prime factor of a number
{
    int n;
    cin >> n;
    int spf;
    if (isitPrime(n))
    {
        spf = n;
    }
    else
    {
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                spf = i;
                break;
            }
        }
    }

    cout << spf << endl;
    return 0;
}