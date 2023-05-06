#include <bits/stdc++.h>
using namespace std;

// Speed
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Abid cout.tie(NULL);

using vi = vector<int>;
using vs = vector<string>;
using ll = long long;

#define mod 100000007
#define endl '\n'
#define coutall(v)         \
    for (auto &it : v)     \
        cout << it << ' '; \
    cout << endl;

void solve()
{
    ll n, m;
    cin >> n >> m;
    int v[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    int i = 0, j = m - 1;
    int x;
    cin >> x;
    vector<int> v1(2);
    v1[0] = -1;
    v1[1] = -1;
    while (i >= 0 && i < n && j >= 0 && j < m)
    {
        if (v[i][j] == x)
        {
            v1[0] = i;
            v1[1] = j;
            break;
        }
        else if (v[i][j] < x)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << v1[0] << " " << v1[1] << endl;
}

int main()
{
    // Code By Abid
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}