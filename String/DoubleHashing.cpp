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
#define endl '\n'
#define print(x) cout << " >> " << #x << " : " << x << endl
#define coutall(v) for (auto &it : v)cout << it << ' ';cout << endl;
const int N = 1e6 + 10;
const int Base1 = 137;
const int Base2 = 277;
const ll mod1 = 1e9+7;
const ll mod2 = 1e9+9;
// ll h[N + 5], power[N + 5];
pair<ll,ll>h[N];
pair<ll,ll>power[N];
void GeneratePrefixHash(string s) // create an array of hash value of the prefix of the string
{
    h[0].first = s[0];
    for (int i = 1; i < s.size(); i++) // storing hash value of every prefix of the string based on ascii value
    {
        h[i].first = ((h[i - 1].first * Base1) + s[i]) % mod1;
    }
    h[0].second = s[0];
    for (int i = 1; i < s.size(); i++) // storing hash value of every prefix of the string based on ascii value
    {
        h[i].second = ((h[i - 1].second * Base2) + s[i]) % mod2;
    }
    power[0].first = 1;
    for (int i = 1; i < s.size(); i++) // storing power of the base upto string length
    {
        power[i].first = (power[i - 1].first * Base1) % mod1;
    }
    power[0].second = 1;
    for (int i = 1; i < s.size(); i++) // storing power of the base upto string length
    {
        power[i].second = (power[i - 1].second * Base2) % mod2;
    }
}
pair<int,int> getHashVal(string s) // return hash value of a string
{
    pair<ll,ll>H={0,0};
    for (int i = 0; i < s.size(); i++){
        H.first = ((H.first * Base1) + s[i]) % mod1;
    }
    for (int i = 0; i < s.size(); i++){
        H.second = ((H.second * Base2) + s[i]) % mod2;
    } 
    return H;
}
pair<int,int> getRangeHash(int l, int r) // return hash value of a range
{
    pair<ll,ll>Hs;
    if (l == 0){
        return h[r];
    }
    Hs.first=(h[r].first - (h[l - 1].first * power[r - l + 1].first % mod1) + mod1) % mod1;
    Hs.second=(h[r].second - (h[l - 1].second * power[r - l + 1].second % mod2) + mod2) % mod2;
    return Hs;
}
void solve()
{
     int n;
    // cin >> n;
    while (cin >> n)
    {
        string p, s;
        cin >> p >> s;
        GeneratePrefixHash(s);
        pair<ll,ll>hashValOfp = getHashVal(p);
        int cnt = 0;
        for (int i = 0; i + p.size() <= s.size(); i++)
        {
            pair<ll,ll>range = getRangeHash(i, i + p.size() - 1);
            if (range==hashValOfp)
            {
                cout << i << endl;
                cnt++;
            }
        }
        if (cnt == 0)
        {
            cout << endl;
        }
        // cout << endl;
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