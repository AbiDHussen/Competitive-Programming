#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
bool vis[N];
vector<int> g[N];
bool dfs(int vartex, int par)
{
    vis[vartex] = true;
    bool isLoopExist = false;
    for (int child : g[vartex])
    {
        if (vis[child] && child == par)
            continue;
        if (vis[child])
            return true;
        isLoopExist |= dfs(child, vartex);
    }
    return isLoopExist;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    bool isLoopExist = false;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        if (dfs(i, 0))
        {
            isLoopExist = true;
            break;
        }
    }
    cout << isLoopExist << endl;
    return 0;
}