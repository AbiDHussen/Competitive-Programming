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
int par[N];
int s[N];
void make(int v)
{
    par[v] = v;
    s[v] = 1;
}
int find(int v)
{
    if (v == par[v])
    {
        return v;
    }
    // path compression
    par[v] = find(par[v]);
    return par[v];
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        // union by size
        if (s[a] < s[b])
        {
            swap(a, b);
        }
        par[b] = a;
        s[a] += s[b];
    }
}
void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    while (k--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    int cc = 0;
    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)
        {
            cc++;
        }
    }
    cout << cc << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << par[i] << " ";
    }
    cout << endl;
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