#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define mod 100000007
// #define int long long
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
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 1e5 + 10;
void solve()
{
    int n, m;
    cin >> n;
    vector<int> v(n + 5);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
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
