#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

struct pair_hash // if you want to use pair in gp hash table and unordered map you need to pass the function as a parameter in the gp hash table or unordered map
{ 
    template <typename T, typename U>
    size_t operator()(const pair<T, U> &p) const
    {
        auto hash1 = hash<T>{}(p.first);
        auto hash2 = hash<U>{}(p.second);
        return hash1 ^ hash2;
    }
};

int32_t main()
{
    int n, k;
    cin >> n;
    // gp_hash_table<pair<ll, int>, int, pair_hash> gph;
    gp_hash_table<char, int> gph; // SAME AS unordered_map; But it is More Faster and takes more memory than unordered map;
    for (int i = 0; i < n; i++)
    {
        char ch;
        cin >> ch >> k;
        gph[ch] = k;
    }
    for (auto i : gph)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << gph.find('c')->second << endl;
    return 0;
}