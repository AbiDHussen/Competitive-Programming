// Problem Link : https://cses.fi/problemset/task/1137

#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007
#define int long long
#define all(x)      x.begin(),x.end()
#define allr(x)     x.rbegin(),x.rend()
#define CheckBit(x,k)   (x & (1LL << k))
#define SetBit(x,k)     (x |= (1LL << k))
#define ClearBit(x,k)   (x &= ~(1LL << k))
#define LSB(mask)       __builtin_ctzll(mask)
#define MSB(mask)       63-__builtin_clzll(mask) 
#define print(x)    cout << #x << " : " << x << endl
#define error1(x)   cerr << #x << " = " << (x) <<endl
#define coutall(v)  for(auto &it: v) cout<<it<<' '; cout<<endl
#define Abid_52     ios::sync_with_stdio(false);cin.tie(0),cin.tie(0)
#define error2(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n"
#define UNIQUE(x)   sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()
template <typename T, typename U> T ceil(T x, U y) {return (x > 0 ? (x + y - 1) / y : x / y);}
template <typename T, typename U> T floor(T x, U y) {return (x > 0 ? x / y : (x - y + 1) / y);}

const int N = 2e5 + 10;
vector<int>g[N];
vector<int>flat(2 * N + 5), v(N);
map<int,int>firstOc,lastOc;
int id = 0;

int tree[8 * N];

void build(int node, int st, int en)//node 1 based
{
    if (st == en)
    {
        tree[node] = flat[st];
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid);                         // divide left side
    build(2 * node + 1, mid + 1, en);                 // divide right side
    tree[node] = tree[2 * node] + tree[2 * node + 1]; // sum of left and right side
}
int query(int node, int st, int en, int l, int r)
{
    if (st > r || en < l) // No overlapping and out of range
    {
        return 0;
    }
    if (l <= st && en <= r) // Complete overlapped (l-r in range)
    {
        return tree[node];
    }
    // Partial overlapping
    int mid = (st + en) / 2;

    int q1 = query(2 * node, st, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, en, l, r);
    return q1 + q2;
}
void update(int node, int st, int en, int idx, int val)
{
    if (st == en)
    {
        flat[st] = val;
        tree[node] = val;
        return;
    }
    int mid = (st + en) / 2;
    int left = 2 * node, right = 2 * node + 1;
    if (idx <= mid) update(left, st, mid, idx, val);
    else update(right, mid + 1, en, idx, val);
    tree[node] = tree[left] + tree[right];
}

void dfs(int node, int par){
    firstOc[node] = ++id;
    flat[id] = v[node];
    for(auto it : g[node]){
        if(it != par){
            dfs(it, node);
        }
    }
    lastOc[node] = ++id;
    // flat[id] = 0;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    build(1, 1, 2 * n);
    while(m--){
        int type;
        cin >> type;
        if(type == 1){
            int node, val;
            cin >> node >> val;
            int id = firstOc[node];
            update(1, 1, 2 * n, id, val);
        }
        else{
            int node;
            cin >> node;
            ll ans = query(1, 1, 2 * n, firstOc[node], lastOc[node]);
            cout << ans << endl;
        }
    }
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