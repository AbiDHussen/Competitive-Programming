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
    int start = 0, end = n - 1;
    int res;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int prev = (mid + n - 1) % n;
        cout << start << " " << mid << " " << end << endl;
        if (v[mid] < v[prev])
        {
            res = mid;
            // return;
            break;
        }
        else if (v[mid] < v[end])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << v[res] << endl;
    // int x;
    // cin >> x;
    // auto it1 = res + v.begin();
    // auto it2 = res - 1 + v.begin();
    // int ans1 = binary_search(v.begin(), it2, x);
    // int ans2 = binary_search(it1, v.end(), x);
    // ans1 == 1 || ans2 == 1 ? cout << "found" << endl : cout << "NOT found" << endl;
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