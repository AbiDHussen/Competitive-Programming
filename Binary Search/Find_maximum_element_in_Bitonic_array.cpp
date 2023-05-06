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
    int start = 0, end = v.size() - 1;
    int res;
    if (v.size() == 1)
    {
        cout << "0" << endl;
        return;
    }
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (mid > 0 && mid < v.size() - 1)
        {
            if (v[mid] > v[mid - 1] && v[mid] > v[mid + 1])
            {
                res = mid;
                break;
            }
            else if (v[mid] < v[mid + 1])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        else if (mid == 0)
        {
            if (v[0] > v[1])
            {
                cout << "0" << endl;
                return;
            }
            else
            {
                cout << "1" << endl;
                return;
            }
        }
        else if (mid == v.size() - 1)
        {
            if (v[v.size() - 1] > v[v.size() - 2])
            {
                cout << v.size() - 1 << endl;
                return;
            }
            else

            {
                cout << v.size() - 2 << endl;
                return;
            }
        }
    }
    cout << res << endl;
}

int main()
{
    // Code By Abid
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}