#include <bits/stdc++.h>
using namespace std;

// Speed
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Abid cout.tie(NULL);

using vi = vector<int>;
using vs = vector<string>;
using ll = long long;
#define print(x) cout << " >> " << #x << " : " << x << endl

#define f first
#define s second
#define pb push_back
#define sva sort(v.begin(), v.end())
#define svd sort(v.rbegin(), v.rend())
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mod 100000007
const int N = 1e3 + 10;
bool ans = false;
bool vis[N][N];
int n, m;
int grid[N][N];
int moves[N][N];
int s1,s2;
int d1,d2;
// Direction vectors
int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };
 
// Function to check if a cell
// is Valid or not
bool isValid(int i,int j){
    if(i<0 || i>=n)return false;
    if(j<0 || j>=m)return false;
    if(vis[i][j])return false;
    return true;
}
// Function to perform the BFS traversal
void BFS(int i,int j)
{
    // Stores indices of the matrix cells
    queue<pair<int, int> > q;
 
    // Mark the starting cell as visited
    // and push it into the queue
    q.push({ i, j });
    moves[i][j]=0;
    vis[i][j] = true;
 
    // Iterate while the queue
    // is not empty
    while (!q.empty()) {
 
        pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
        if(x==d1 && y==d2)return;
        q.pop();
        // Go to the adjacent cells
        for (int i = 0; i < 4; i++) {
 
            int adjx = x + dRow[i];
            int adjy = y + dCol[i];
            if (isValid(adjx, adjy)) {
                q.push({ adjx, adjy });
                moves[adjx][adjy]=moves[x][y]+1;
                vis[adjx][adjy] = true;
            }
        }
    }
}
void reset(int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            grid[i][j]=0;
            vis[i][j]=0;
            // moves[i][j]=0;
        }
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    cin>>s1>>s2;
    cin>>d1>>d2;
    BFS(s1,s2);//required BFS call
}

int main()
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