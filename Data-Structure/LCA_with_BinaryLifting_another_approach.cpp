// code form youtube channel washuu
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
const int Log = 18;
vector<int> g[N + 1];
int timer = 0;
int tin[N + 1];  // for node entering time
int tout[N + 1]; // for node existing time
int table[N + 1][Log + 1];
int level[N + 1];
void reset()
{
    for (int i = 0; i < N; i++)
    {
        g[i].clear();
        for (int j = 0; j < Log; j++)
        {
            table[i][j] = -1;
        }
    }
    timer = 0;
}
void dfs(int node, int par, int lev = 0)
{
    tin[node] = ++timer; // node entering time
    table[node][0] = par;
    level[node] = lev;
    for (int i = 1; i < Log; i++)
    {
        int p = table[node][i - 1];
        table[node][i] = table[p][i - 1];
    }
    for (int child : g[node])
    {
        if (child != par)
        {
            dfs(child, node, lev + 1);
        }
    }
    tout[node] = ++timer; // node existing time
}
bool isAncestor(int u, int v) // check if u is ancestor of v or not
{
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}
int lca(int u, int v)
{
    if (isAncestor(u, v))
    {
        return u;
    }
    if (isAncestor(v, u))
    {
        return v;
    }
    for (int i = Log - 1; i >= 0; i--)
    {
        if (!isAncestor(table[u][i], v))
        {
            u = table[u][i];
        }
    }
    return table[u][0];
}
int distance(int u, int v) // distance between two node u and v
{
    int l = lca(u, v);
    return level[u] + level[v] - (level[l] << 1); // level[u]+level[v]-2*level[lca(u,v)]
}
int kth(int u, int k)
{
    for (int i = 0; i <= lg; i++)
        if (k & (1 << i))
            u = table[u][i];
    return u;
}
int findKth(int u, int v, int k) // kth node from u to v, 0th node is u
{
    int l = lca_query(u, v);
    int d = level[u] + level[v] - (level[l] << 1);
    if (level[l] + k <= level[u])
        return kth(u, k);
    k -= level[u] - level[l];
    return kth(v, level[v] - level[l] - k);
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= 10; j++)
    //     {
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
        // cout << distance(a, b) << endl;
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