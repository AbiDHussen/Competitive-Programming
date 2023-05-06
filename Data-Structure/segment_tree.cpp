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
int arr[] = {5, 1, 2, 6, 3, 5, 9};
int tree[N];
void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;
    init(left, b, mid);
    init(right, mid + 1, e);
    tree[node] = tree[left] + tree[right];
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
    {
        return 0;
    }
    if (b >= i && e <= j)
    {
        return tree[node];
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;
    int leftSum = query(left, b, mid, i, j);
    int rightSum = query(right, mid + 1, e, i, j);
    return leftSum + rightSum;
}
void update(int node, int b, int e, int target, int val)
{
    if (target > e || target < b)
    {
        return;
    }
    if (b == e && target == b)
    {
        tree[node] = val;
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;
    update(left, b, mid, target, val);
    update(right, mid + 1, e, target, val);
    tree[node] = tree[left] + tree[right];
}
void solve()
{
    init(0, 0, 6);
    // cout << tree[1] << endl;
    cout << query(0, 0, 6, 2, 5) << endl;
    update(0, 0, 6, 1, 5);
    cout << tree[0] << endl;
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