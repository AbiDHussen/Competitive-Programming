//Problem Link : https://cses.fi/problemset/task/1648/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;

template <class T>
struct BIT { // 1-indexed
    int n;
    vector<T> t;
    BIT() {}
    BIT(int _n) {
        n = _n;
        t.assign(n + 1, 0);
    }
    T query(int i) {
        T ans = 0;
        for (; i >= 1; i -= (i & -i)) ans += t[i];
        return ans;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
    void update(int i, T val) {
        if (i <= 0) return;
        for (; i <= n; i += (i & -i)) t[i] += val;
    }
    void update(int l, int r, T val) {
        upd(l, val);
        upd(r + 1, -val);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> val(n + 1);
    BIT<ll> bit1(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> val[i];
        bit1.update(i, val[i]);
    }

    while(q--){
        short type;
        cin >> type;
        if(type == 1){
            int id, v;
            cin >> id >> v;
            bit1.update(id, -val[id]);//reduce the current value to zero
            val[id] = v;
            bit1.update(id, val[id]);//add the new value
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << bit1.query(l, r) << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}
