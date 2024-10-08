#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int N = 5e5 + 9;
int a[N];
struct ST
{
    #define lc (n << 1)
    #define rc ((n << 1) | 1)
    ll t[4 * N], lazy[4 * N];
    ST()
    {
        for (int i = 0; i < 4 * N; i++)
            t[i] = lazy[i] = 0;
    }
    inline void push(int n, int st, int en)
    {
        if (lazy[n] == 0) return;
        t[n] = lazy[n];
        if (st != en)
        {
            lazy[lc] =lazy[n];
            lazy[rc] =lazy[n];
        }
        lazy[n] = 0;
    }
    inline void pull(int n)
    {
        t[n] = max(t[lc],t[rc]);
    }
    void build(int n, int st, int en)
    {
        lazy[n] = 0;
        if (st == en)
        {
            t[n] = a[st];
            return;
        }
        int mid = (st + en) >> 1;
        build(lc, st, mid);
        build(rc, mid + 1, en);
        pull(n);
    }
    void update(int n, int st, int en, int l, int r, ll v)//replace a segment l to r with value x
    {
        push(n, st, en);  // push the value left and right child
        if (r < st || en < l) return;
        if (l <= st && en <= r)
        {
            lazy[n] = v; // set lazy
            push(n, st, en);
            return;
        }
        int mid = (st + en) >> 1;
        update(lc, st, mid, l, r, v);
        update(rc, mid + 1, en, l, r, v);
        pull(n);
    }
    inline ll combine(ll a, ll b)
    {
        return max(a,b);
    }
    ll query(int n, int st, int en, int l, int r)//find max element of segment l to r;
    {
        push(n, st, en);
        if (l > en || st > r) return INT_MIN; // return null
        if (l <= st && en <= r) return t[n];
        int mid = (st + en) >> 1;
        return combine(query(lc, st, mid, l, r), query(rc, mid + 1, en, l, r));
    }
} st;

int32_t main()
{
    int n, q, l, r, v;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    st.build(1, 1, n); // Building the Segment tree
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cin >> l >> r >> v;
            st.update(1, 1, n, l, r, v);
        }
        else
        {
            cin >> l >> r;
            cout << st.query(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}