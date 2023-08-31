#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3 + 10;
vector<int> g[N];
bool vis[N];
vector<vector<int>> cc;
vector<int> ccc;
void dfs(int vartex)
{
    ccc.push_back(vartex);
    vis[vartex] = true;
    for (int child : g[vartex])
    {
        if (vis[child])
            continue;
        dfs(child);
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int cnt = 0;
    for (int i = 1; i <= v; i++)
    {
        if (vis[i])
        {
            continue;
        }
        ccc.clear();
        dfs(i);
        cc.push_back(ccc);
        cnt++;
    }
    cout << cnt << endl;
    // for (auto ccc : cc)
    // {
    //     for (int vartex : ccc)
    //     {
    //         cout << vartex << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}