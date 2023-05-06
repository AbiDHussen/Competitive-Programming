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
const int N = 1e5 + 10;
int arr[] = {0, 0, 0, 0, 0, 0, 0, 0};
struct Tree
{
    int sum, prop;
} tree[N];
void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node].sum = arr[b];
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;
    init(left, b, mid);
    init(right, mid + 1, e);
    tree[node].sum = tree[left].sum + tree[right].sum;
}
int query(int node, int b, int e, int i, int j, int pro = 0)
{
    if (i > e || j < b)
    {
        return 0;
    }
    if (b >= i && e <= j)
    {
        return tree[node].sum + ((e - b + 1) * (pro));
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;
    int leftSum = query(left, b, mid, i, j, pro + tree[node].prop);
    int rightSum = query(right, mid + 1, e, i, j, pro + tree[node].prop);
    return leftSum + rightSum;
}
void update(int node, int b, int e, int i, int j, int val)
{
    if (i > e || j < b)
    {
        return;
    }
    if (b >= i && e <= j)
    {
        tree[node].sum += (e - b + 1) * val;
        tree[node].prop += val;
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;
    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);
    tree[node].sum = tree[left].sum + tree[right].sum+((e-b+1)*tree[node].prop);
}
void solve()
{
    init(0, 0, 7);
    // cout << tree[1] << endl;
    // cout << query(0, 0, 6, 2, 5, 0);
    cout << query(0, 0, 7, 3, 5) << endl;
    update(0, 0, 7, 2, 5, 2);
    // update(0, 0, 7, 3, 7, 3);
    cout << query(0, 0, 7, 2, 5) << endl;
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