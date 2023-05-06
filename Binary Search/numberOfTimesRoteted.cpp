#include <bits/stdc++.h>
using namespace std;

// Speed
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Abid cout.tie(NULL);

using vi = vector<int>;
using vs = vector<string>;
using ll = long long;

#define mod 100000007
#define endl '\n'
#define coutall(v)         \
    for (auto &it : v)     \
        cout << it << ' '; \
    cout << endl;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int l = 0, h = n - 1;
    if (v[l] < v[h] || n == 1)
    {
        cout << "0" << endl;
        return;
    }
    while (h >= l)
    {

        int m = (l + h) / 2;
        int next = (m + 1) % n;
        int prev = (m + n - 1) % n;
        cout << m << " " << next << " " << prev << endl;
        if (v[prev] > v[m])
        {
            cout << m << endl;
            return;
        }
        else if (v[m] > v[h])
        {
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }
}

int main()
{
    // Code By Abid
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}