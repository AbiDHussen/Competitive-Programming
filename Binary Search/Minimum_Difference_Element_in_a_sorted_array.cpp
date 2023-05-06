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
    int x;
    cin >> x;
    int start = 0, end = n - 1;
    int res = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (v[mid] == x)
        {
            // cout<<v[mid]<<endl;
            res = v[mid];
            return;
        }
        else if (v[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    if (res != -1)
    {
        cout << res << endl;
    }
    else
    {
        int ans = abs(x - v[start]);
        int ans1 = abs(x - v[end]);
        cout << min(ans, ans1) << endl;
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