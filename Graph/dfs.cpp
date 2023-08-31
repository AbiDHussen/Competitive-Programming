#include <bits/stdc++.h>
using namespace std;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Abid cout.tie(NULL);
// #define int long long
#define endl '\n'
#define print(x) cout << " >> " << #x << " : " << x << endl
#define coutall(v) for (auto &it : v)cout << it << ' ';cout << endl;
const int N=1e3+10;
int vis[N];
vector<int>g[N];
void dfs(int source)
{
    vis[source]=1;

    for(int child:g[source])
    {
        if(!vis[child])
        {
            dfs(child);
        }
    }
}
void solve()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
}
int32_t main()
{
    // Code By Abid
    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }
}