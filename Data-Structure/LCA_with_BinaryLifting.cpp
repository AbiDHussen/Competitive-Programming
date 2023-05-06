//code from youtube channel CodeNCode
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
#define pb push_back
#define mod 100000007
#define endl '\n'
#define coutall(v)         \
    for (auto &it : v)     \
        cout << it << ' '; \
    cout << endl;
const int N = 1e5 + 10;
vector<int> g[N];
const int maxN = 21;
int level[N], LCA[N][maxN + 1];
//code from youtube channel CodeNCode
void dfs(int node, int lvl, int par)
{
    level[node] = lvl;
    LCA[node][0] = par;
    for (int child : g[node])
    {
        if (child != par)
        {
            dfs(child, lvl + 1, node);
        }
    }
}
void init(int n)
{
    dfs(1, 0, -1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxN; j++)
        {
            if (LCA[i][j - 1] != -1)
            {
                int par = LCA[i][j - 1];
                LCA[i][j] = LCA[par][j - 1];
            }
        }
    }
}
int getLCA(int a, int b)
{
    if (level[b] < level[a])
        swap(a, b);
    int d = level[b] - level[a];
    while (d > 0)
    {
        int i = log2(d);
        b = LCA[b][i];
        d -= 1 << i;
    }
    if (a == b)
        return a;
    for (int i = maxN; i >= 0; i--)
    {
        if (LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
        {
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    return LCA[a][0];
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 0; j <= maxN; j++)
        {
            LCA[i][j] = -1;
        }
    }
    g[1].pb(2);
    g[1].pb(3);
    g[3].pb(4);
    g[3].pb(5);
    init(5);
    cout << getLCA(2, 5);
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