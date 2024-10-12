//Problem Link : https://lightoj.com/problem/matrix-game
//Nim Game Blog Link : http://www.shafaetsplanet.com/?p=2608
#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007
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

const int N = 2e5 + 10;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll>v;
    for (int i = 0; i < n; i++)
    {
        ll sum = 0;
        for(int j = 0 ; j < m; j++){
            int x;
            cin >> x;
            sum += x;
        }
        v.push_back(sum);
    }
    ll x_or = v[0];
    for(int i = 1; i < n; i++){
        x_or = (x_or ^ v[i]);
    }

    if(x_or == 0){
        cout << "Bob" << endl;
    }
    else{
        cout << "Alice" << endl;
    }
}

int32_t main()
{
    Abid_52;
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        cout << "Case " << tc << ": ";
        solve();
    }
}