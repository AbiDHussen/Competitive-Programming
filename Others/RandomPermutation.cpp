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
#define mod 100000007
#define endl '\n'
#define all(x) x.begin(), x.end()
#define coutall(v)         \
    for (auto &it : v)     \
        cout << it << ' '; \
    cout << endl;
const int N = 1e5 + 10;
void solve()
{
    ll n = 4, sum = 0;
    vector<ll> v(n);
    iota(all(v), 1);
    coutall(v);
    do
    {
        // coutall(v);
        set<ll> st;
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += v[i];
            sum %= n;
            st.insert(sum);
        }
        if (st.size() == n)
        {
            for (auto i : v)
                cout << i << " ";
            cout << endl;
        }
    } while (next_permutation(all(v)));
}

int32_t main()
{
    // Code By Abid
    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        // cout << "Case " << tc << ":";
        solve();
    }
}