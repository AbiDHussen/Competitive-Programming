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
        res = 0;
    }
    else
    {
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
                    res = 0;
                    break;
                }
                else
                {
                    res = 1;
                    break;
                }
            }
            else if (mid == v.size() - 1)
            {
                if (v[v.size() - 1] > v[v.size() - 2])
                {
                    res = v.size() - 1;
                    break;
                }
                else

                {
                    res = v.size() - 2;
                    break;
                }
            }
        }
    }
    int x;
    cin >> x;
    int ans = binary_search(v.begin(), res - 1 + v.begin(), x);
    int low = res;
    int high = n - 1;
    int ans1 = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (x == v[mid])
        {
            ans1 = mid;
            break;
        }
        else if (x < v[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << " " << ans1 << endl;
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