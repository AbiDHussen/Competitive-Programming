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
    int start = 0, end = 1;
    while (v[end] != 1)
    {
        start = end;
        end = end * 2;
    }
    // cout << start << " " << end << endl;
    int res = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (v[mid] == 1)
        {
            res = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << res << endl;
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