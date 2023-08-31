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
const int N = 1e5 + 10;
void solve()//time complexity=O(sqrt(n))
{
    int n;
    cin >> n;
    vector<int> div;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            div.push_back(i);
            if(i!=n/i)div.push_back(n/i);
        }
    }
    sort(div.begin(),div.end());
    coutall(div);
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
    main();
}