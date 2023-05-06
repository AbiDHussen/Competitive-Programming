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
    vector<char> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    char x;
    cin >> x;
    if (upper_bound(v.begin(), v.end(), x) == v.end())
    {
        cout << v[0] << endl;
    }
    else
    {
        auto y = upper_bound(v.begin(), v.end(), x);
        cout << v[y - v.begin()] << endl;
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