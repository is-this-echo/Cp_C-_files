/* Debjyoti Ghosh*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define INF 2e18
#define PI 3.1415926535897932384626
#define mod 998244353
#define f first
#define s second 

double eps = 1e-12;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void google(int t) {cout << "Case #" << t << ": ";}
    
 
vector<int> dx{0, 0, 1, -1};
vector<int> dy{1, -1, 0, 0};

int dfs(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp,
        int m, int n, int i, int j, int steps)
{
    if (i < 0 || i >= m || j < 0 || j >= n)
        return INT_MIN;

    if (steps == 0)
        return grid[i][j];

    if (dp[i][j][steps] != INT_MIN)
        return dp[i][j][steps];

    int best = INT_MIN;
    for (int k = 0; k < dx.size(); ++k)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];
        best = max(best, dfs(grid, dp, m, n, nx, ny, steps - 1));
    }

    return dp[i][j][steps] = grid[i][j] + best;
}

// TC = O(m*n*k) with cache, O(4^n) without cache
// SC = O(m*n*k) for cache, else O(k) for call stack only
int maxPathSum(vector<vector<int>>& grid, int startR, int startC, int steps)
{
    int m = grid.size();
    int n = grid[0].size();

    // dp[i][j][k]  -> max path sum from (i,j) with exactly k steps remaining 
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(steps + 1, INT_MIN)));

    return dfs(grid, dp, m, n, startR, startC, steps);
}

    
int main()
{
    fastio();

    vector<vector<int>> grid =
    {
        {2, 3, 4, 6},
        {1, 2, 3, 5},
        {3, 4, 0, 5},
        {0, 1, 2, 3}
    };

    int startR = 2, startC = 2, N = 3;
    cout << maxPathSum(grid, startR, startC, N) << endl;
 
    return 0;
}