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
const int N = 1e5 + 10;
struct node
{
    bool endmark;
    node* next[27];
    node()
    {
        endmark=false;
        for(int i=0;i<26;i++)
        {
            next[i]=NULL;
        }
    }
}*root;
void insert(string s)
{
    node* curr = root;
    for(int i=0;i<s.size();i++)
    {
        int id=s[i]-'a';
        if(curr->next[id]==NULL)
        {
            curr->next[id]=new node();
        }
        curr=curr->next[id];
    }
    curr->endmark=1;
}
bool search(string s)
{
    node* curr=root;
    for(int i=0;i<s.size();i++)
    {
        int id=s[i]-'a';
        if(curr->next[id]==NULL)
        {
            return false;
        }
        curr=curr->next[id];
    }
    return curr->endmark;
}
void solve()
{
    int n;
    cin >> n;
    // vector<int> v(n);
    // for (ll i = 0; i < n; i++)
    // {
    //     cin >> v[i];
    // }
}

int32_t main()
{
    // Code By Abid
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        // cout << "Case " << tc << ":";
        solve();
    }
}