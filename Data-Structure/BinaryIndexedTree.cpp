#include <bits/stdc++.h>
using namespace std;

// Speed
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Abid cout.tie(NULL);

using vi = vector<int>;
using vs = vector<string>;
using ll = long long;

// #define int long long
#define mod 100000007
#define endl '\n'
#define coutall(v)         \
    for (auto &it : v)     \
        cout << it << ' '; \
    cout << endl;
const int N = 1e5 + 10;
int tree[N];
int query(int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        // cout << idx << " ";
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    // cout << endl;
    return sum;
}
void update(int idx, int val, int n)
{
    while (idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n+10);
    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
        update(i, v[i], n);
    }
    cout << query(6) << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
    cout << query(7) - query(2) << endl;//query range 3 to 7
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