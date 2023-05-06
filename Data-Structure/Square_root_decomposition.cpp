#include <bits/stdc++.h>
using namespace std;

// Speed
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Abid cout.tie(NULL);

using vi = vector<int>;
using vs = vector<string>;
using ll = long long;

#define int long long
#define mod 100000007
#define endl '\n'
#define coutall(v)         \
    for (auto &it : v)     \
        cout << it << ' '; \
    cout << endl;
const int N = 1e5 + 10;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int res = (sqrt(n)) + 1;
    int a[res];
    for (int i = 0; i < res; i++)
    {
        a[i] = INT_MAX;
    }
    for (int i = 0; i < n; i++)
    {
        a[i / res] = min(a[i / res], v[i]);
    }
    // coutall(a);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int mn = INT_MAX;
        for (int i = l; i <= r;)
        {
            if ((i % res) == 0 && (i + res - 1) <= r)
            {
                mn = min(mn, a[i / res]);
                i += res;
            }
            else
            {
                mn = min(mn, v[i]);
                i++;
            }
        }
        cout << mn << endl;
    }
}

int32_t main()
{
    // Code By Abid
    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        // cout << "Case " << tc << ":";
        solve();
    }
}