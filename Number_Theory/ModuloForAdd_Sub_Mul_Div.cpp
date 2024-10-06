//Add : (A+B)%P=((A%P)+(B%P))%P;
//Sub : (A-B)%P=((A%P)-(B%P))%P;
//Mul : (A*B)%P=((A%P)*(B%P))%P;
//Div : it's not same as above;
//(A/B)%P=A*Modulo Multiplicative Inverse of B(MMI(B))=((A%P)*(MMI(B)%P))%P;
//Now Question is that how to find Modulo Multiplicative inverse??
//ans : It can be find by Fermat's Little Theorem.(a^m-1=1 mod m);
//MMI(B) under Modulo P=B^(P-2)

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define ll long long
#define mod 1000000007
#define Abid_52     ios::sync_with_stdio(false);cin.tie(0),cin.tie(0)
const int N = 1e5 + 10;
ll FindPow(ll base, ll pow) // time complexity=O(log(base))
{
    ll res = 1;
    while (pow)
    {
        pow = pow % mod;
        if (pow % 2 == 1)
        {
            res = (res * base) % mod;
            pow--;
        }
        else
        {
            base = (base * base) % mod;
            pow /= 2;
        }
    }
    return res % mod;
}
void solve()
{
    int a,b,m;
    cin>>a>>b>>m;
    //Find a/b under modulo m
    ll mmiB=FindPow(b,m-2);
    ll ans=((a%m)*(mmiB%m))%m;//correct way
    ll ans1=((a%m)/(b%m))%m;//wrong way
    cout<<ans<<endl;
    cout<<ans1<<endl;
}
int32_t main()
{
    Abid_52;
    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }
}