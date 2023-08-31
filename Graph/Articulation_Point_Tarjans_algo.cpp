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
vector<bool>AP(N);
int n,m;
int t=0;
void dfs(int u)
{
    disc[u]=low[u]=t;
    t++;
    int child=0;
    for(auto v : g[u])
    {
        if(disc[v]==-1)//if v is not visited
        {
            child++;
            par[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);

            if(par[u]==-1 && child>1)//case 1 : if u is root and u has more than one child
            {
                AP[u]=1;
            }
            if(par[u]!=-1 && low[v]>=disc[u])//case 2 : if u is not root and there is no backedge from v to ancestor of u
            {
                AP[u]=1;
            }
        }
        else if(v!=par[u])
        {
            low[u]=min(low[u],disc[v]);
        }
    }
}
void findAP()
{
   for(int i=0;i<n;i++)
   {
        if(disc[i]==-1)
        {
            dfs(i);
        }
   }
   cout<<"Articulation Points are : ";
   for(int i=0;i<n;i++)
   {
        if(AP[i])
        {
            cout<<i<<" ";
        }
   }
   cout<<endl;
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
    findAP();
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