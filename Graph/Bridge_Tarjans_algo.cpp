//Code : Articulation Point
// Time Complexity : O(V+E)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define mod 100000007
// #define int long long
#define all(x)      x.begin(),x.end()
#define print(x) cout << #x << " : " << x << endl
#define error1(x)   cerr << #x << " = " << (x) <<endl
#define coutall(v)  for(auto &it: v) cout<<it<<' '; cout<<endl
#define Abid_52   ios::sync_with_stdio(false);cin.tie(0),cin.tie(0)
#define error2(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n"
const int N = 1e5 + 10;
vector<int>g[N];
vector<int>disc(N,-1);
vector<int>low(N,-1);
vector<int>par(N,-1);
vector<pair<int,int>>Bridge;
int n,m;
int t=0;
void dfs(int u)
{
    disc[u]=low[u]=t;
    t++;
    for(auto v : g[u])
    {
        if(disc[v]==-1)//if v is not visited
        {
            par[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);

            if(low[v]>disc[u])//if there is no backedge from v to ancestor of u 
            {
                Bridge.push_back({u,v});
            }
        }
        else if(v!=par[u])//Ignoring child to parent edge
        {
            low[u]=min(low[u],disc[v]);//handling backedges
        }
    }
}
void findBridge()
{
   for(int i=0;i<n;i++)
   {
        if(disc[i]==-1)
        {
            dfs(i);
        }
   }
   cout<<"Bridges are : \n";
   for(auto it : Bridge)
   {
        cout<<it.first<<" "<<it.second<<endl;
   }
}

void solve()
{
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    findBridge();
}
int32_t main()
{
    Abid_52;
    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }
}