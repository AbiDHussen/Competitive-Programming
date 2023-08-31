// code from Youtube Channel LoveExtendsCode
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
const int N = 2e5 + 10;
// int tree[N];
int bit1[N];
int bit2[N];
int query(int idx, int *tree) //(Query Time Complexity=O(log(n))
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
ll RangeSum(int l, int r)
{
    ll sum1 = query(r, bit1) * r - query(r, bit2);               // Sum of elements in [1, r]
    ll sum2 = query(l - 1, bit1) * (l - 1) - query(l - 1, bit2); // Sum of elements in [1, l-1]
    return sum1 - sum2;                                          // Sum of elements in [l,r] = Sum of elements in [0,r] - Sum of elements in [0, l-1]
}
void update(int idx, int val, int n, int *tree) //(Update Time Complexity=O(log(n))
{
    while (idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
void RangeUpdate(int l, int r, int val, int n)
{
    update(l, val, n, bit1);
    update(r + 1, -val, n, bit1);
 
    update(l, val * (l - 1), n, bit2);
    update(r + 1, -val * r, n, bit2);
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 10);
    for (ll i = 1; i <= n; i++) // Tree Construction Time Complexity=O(n*log(n))
    {
        cin >> v[i];
        // update(i, v[i], n);
        RangeUpdate(i, i, v[i], n);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << RangeSum(l, r) << endl;
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