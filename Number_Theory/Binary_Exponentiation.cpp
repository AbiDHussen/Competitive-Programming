#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod 1000000007

ll FindPow(ll base, ll pow) // time complexity=O(log(base))
{
    ll res = 1;
    while (pow)
    {
        pow = pow % mod;
        if (pow % 2 == 1)
        {
            res = (res * base) % mod;
            pow--;
        }
        else
        {
            base = (base * base) % mod;
            pow /= 2;
        }
    }
    return res % mod;
}
int main()
{
    long long int base, pow, res = 1;
    cin >> base >> pow;
    ll ans = FindPow(2, 5);
    cout << ans << endl;
}