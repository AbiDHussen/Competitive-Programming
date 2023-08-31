#include <bits/stdc++.h>
using namespace std;

// Speed
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Abid cout.tie(NULL);

using vi = vector<int>;
using vs = vector<string>;
using ll = long long;

#define f first
#define s second
#define pb push_back
#define sva sort(v.begin(), v.end())
#define svd sort(v.rbegin(), v.rend())
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mod 100000007
const int N = 1e3 + 10;
bool ans = false;
bool vis[N][N];
int n, m;
bool isValid(int i,int j){
    if(i<0 || i>=n)return false;
    if(j<0 || j>=m)return false;
    if(vis[i][j])return false;
    return true;
}
void dfs(int i, int j, vector<vector<char>> &g)
{
    if(!isValid(i,j))return;
    //requird conditions
    dfs(i - 1, j, g);//up
    dfs(i + 1, j, g);//down
    dfs(i, j - 1, g);//left
    dfs(i, j + 1, g);//right
}
void solve()
{
    cin >> n >> m;
    vector<vector<char>> g(N);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char z;
            cin >> z;
            g[i].push_back(z);
        }
    }
    //Required DFS calls
}

int main()
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