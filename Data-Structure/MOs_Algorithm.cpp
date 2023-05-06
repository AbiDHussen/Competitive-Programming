#include <bits/stdc++.h>
using namespace std;

// Speed
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Abid cout.tie(NULL);

using vi = vector<int>;
using vs = vector<string>;
using ll = long long;

#define int long long
#define mod 100000007
#define endl '\n'
#define coutall(v)         \
    for (auto &it : v)     \
        cout << it << ' '; \
    cout << endl;
const int N = 1e6 + 10;
int rootN;
struct query
{
    int idx, l, r;
} Q[N];
bool compare(query q1, query q2)
{
    if (q1.l / rootN == q2.l / rootN)
    {
        return q1.r > q2.r;
    }
    return q1.l < q2.l;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    rootN = sqrtl(n);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        Q[i].l = l;
        Q[i].r = r;
        Q[i].idx = i;
    }
    sort(Q, Q + q, compare);
    // for (int i = 0; i < q; i++)
    // {
    //     cout << Q[i].idx << " " << Q[i].l << " " << Q[i].r << endl;
    // }
    vector<int> ans(q);
    int curr_l = 0, curr_r = -1, l, r;
    int curr_ans = 0;
    for (int i = 0; i < q; i++)
    {
        l = Q[i].l;
        r = Q[i].r;
        l--;
        r--;
        while (curr_r < r)
        {
            curr_r++;
            curr_ans += v[curr_r];
        }
        while (curr_l > l)
        {
            curr_l--;
            curr_ans += v[curr_l];
        }
        while (curr_r > r)
        {
            curr_ans -= v[curr_r];
            curr_r--;
        }
        while (curr_l < l)
        {
            curr_ans -= v[curr_l];
            curr_l++;
        }
        ans[Q[i].idx] = curr_ans;
    }
    // coutall(ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
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