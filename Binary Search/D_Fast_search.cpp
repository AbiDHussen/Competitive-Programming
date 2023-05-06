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
int left(vector<int> &v, int x)
{
    int l = 0, h = v.size() - 1;
    while (h >= l)
    {
        int m = (l + h) / 2;
        // cout << l << " " << h << " " << m << " " << x << endl;
        if (v[m] >= x)
        {
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}

int right(vector<int> &v, int x)
{
    int l = 0, h = v.size() - 1;
    while (h >= l)
    {
        int m = (l + h) / 2;
        // cout << l << " " << h << " " << m << " " << x << endl;
        if (v[m] > x)
        {
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return h;
}

void solve()
{
    ll n;
    cin >> n;
    vector<int> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int k;
    cin >> k;
    int l, r;
    while (k--)
    {
        cin >> l >> r;
        int a = left(v, l);
        int b = right(v, r);
        // cout << a << " " << b << endl;
        cout << b - a + 1 << " ";
        // if (k)
        // cout << " ";
    }
    cout << endl;
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