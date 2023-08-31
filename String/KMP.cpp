//code from "LoveExtendsCode" Youtube channel
//Time Complexity--->O(n+m)
#include <bits/stdc++.h>
using namespace std;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Abid cout.tie(NULL);
using vi = vector<int>;
using vs = vector<string>;
using ll = long long;
// #define int long long
#define mod 100000007
#define endl '\n'
#define print(x) cout << " >> " << #x << " : " << x << endl
#define coutall(v) for (auto &it : v)cout << it << ' ';cout << endl;
const int N = 1e5 + 10;
//KMP=Longest prefix that is also a suffix
//we calculate longest prefix that is also a suffix for every i form 0 to n-1
//lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i].
//e.g for string "abcab" it would be [0, 0, 0, 1, 2]
vector<int>ConstructLPSarray(string pattern)//time complexity(O(n))
{
    int n=pattern.length();
    vector<int>lps(n);
    int j=0;
    for(int i=1;i<n;)
    {
        if(pattern[i]==pattern[j])lps[i]=j+1,j++,i++;
        else{
            if(j!=0)j=lps[j-1];
            else lps[i]=j,i++;
        }
    }
    return lps;
}
void KMP(string text,string pattern)
{
    vector<int>lps=ConstructLPSarray(pattern);
    int j=0,i=0;
    //i=text,j=pattern
    int n=text.length();
    int m=pattern.length();
    bool ok=false;
    while(i<n){
        if(text[i]==pattern[j])i++,j++;
        else{
            if(j!=0)j=lps[j-1];
            else i++;
        }
        if(j==m){
            cout<<i-m<<endl;
            j=lps[j-1];
            ok=true;
        }
    }
    if(!ok)cout<<endl;
}
void solve()
{
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        string pattern,text;
        cin>>pattern>>text;
        KMP(text,pattern);
    }
}
int32_t main()
{
    Code By Abid;
    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }
}