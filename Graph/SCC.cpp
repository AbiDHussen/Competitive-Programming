#include <bits/stdc++.h>
using namespace std;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Abid cout.tie(NULL);
using vi = vector<int>;
using vs = vector<string>;
using ll = long long;
// #define int long long
#define mod 100000007
#define endl '\n'
#define print(x) cout << " >> " << #x << " : " << x << endl
#define coutall(v) for (auto &it : v)cout << it << ' ';cout << endl;
const int MX = 1e5 + 10;
vector<int>g[MX],r[MX],comp[MX];
int visited[MX];
int numOfcomp=0;
stack<int>st;
void dfs(int i)
{
    visited[i]=1;
    // print(i);
    for(auto it : g[i])
    {
        if(!visited[it])
        {
            dfs(it);
        }
    }

    st.push(i);
}
void dfs2(int i)
{
    visited[i]=1;
    comp[numOfcomp].push_back(i);
    for(auto it : r[i])
    {
        if(!visited[it])
        {
            dfs2(it);
        }
    }

}
void solve()
{
    int u,v,n,m;
    cin>>n>>m;
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        r[v].push_back(u);
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<i<<"->>";
    //     for(auto it : g[i])
    //     {
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
    // while (!st.empty())
    // {
    //     cout << st.top() <<endl;
    //     st.pop();
    // }
    memset(visited,0,sizeof(visited));
    numOfcomp=0;
    while (!st.empty())
    {
        int x = st.top();
        st.pop();
        if(!visited[x])
        {
            numOfcomp++;
            dfs2(x);
        }
    }

    for(int i=1;i<=numOfcomp;i++)
    {
        cout<<i<<"-->";
        for(auto it : comp[i])
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
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