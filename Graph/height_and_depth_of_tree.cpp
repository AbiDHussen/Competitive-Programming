#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<int> g[N];
int height[N], depth[N];
void dfs(int vartex, int par)
{
    cout << vartex << endl;
    for (int child : g[vartex])
    {
        cout << "par " << vartex << ",child " << child << endl;
        if (child == par)
            continue;
        depth[child] = depth[vartex] + 1;
        dfs(child, vartex);
        height[vartex] = max(height[vartex], height[child] + 1);
    }
}
int main()
{
    int n, m;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << depth[i] << " " << height[i] << endl;
    }
    return 0;
}