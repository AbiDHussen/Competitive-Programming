#include <bits/stdc++.h>
using namespace std;

// Speed
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Abid cout.tie(NULL);

using vi = vector<int>;
using vs = vector<string>;
using ll = long long;

// #define int long long
#define mod 1000000007
#define endl '\n'
#define print(x) cout << " >> " << #x << " : " << x << endl
#define coutall(v)         \
    for (auto &it : v)     \
        cout << it << ' '; \
    cout << endl;
const int N = 1e6 + 10;
const int Base = 129;
ll h[N + 5], power[N + 5];
void GeneratePrefixHash(string s) // create an array of hash value of the prefix of the string
{
    h[0] = s[0];
    for (int i = 1; i < s.size(); i++) // storing hash value of every prefix of the string based on ascii value
    {
        h[i] = ((h[i - 1] * Base) + s[i]) % mod;
    }
    // for (int i = 0; i < s.size(); i++)
    // {
    //     cout << h[i] << endl;
    // }
    power[0] = 1;
    for (int i = 1; i < s.size(); i++) // storing power of the base upto string length
    {
        power[i] = (power[i - 1] * Base) % mod;
    }
}
ll getHashVal(string s) // return hash value of a string
{
    ll H = 0;
    for (int i = 0; i < s.size(); i++)
    {
        H = ((H * Base) + s[i]) % mod;
    }
    return H;
}
ll getRangeHash(int l, int r) // return hash value of a range
{
    if (l == 0)
    {
        return h[r];
    }
    return (h[r] - (h[l - 1] * power[r - l + 1] % mod) + mod) % mod;
}
void solve()
{
    string s="abcab";
    // cin >> s;
    GeneratePrefixHash(s);
    print(getRangeHash(0,1));
    print(getRangeHash(3,4));
    // int ans = getHashVal(s);
    // print(ans);
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