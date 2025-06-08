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
    
 
class Solution {
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

    int dfs(int row, int col, int m, int n, vector<vector<int>>& grid)
    {
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0)
            return 0;

        int currGold = grid[row][col];
        grid[row][col] = 0;
        int maxSubGold = 0;

        for (int k = 0; k < 4; ++k)
        {   
            int nx = row + dx[k];
            int ny = col + dy[k];
            maxSubGold = max(maxSubGold, dfs(nx, ny, m, n, grid));
        }

        grid[row][col] = currGold;
        return maxSubGold + currGold;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int maxGold = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] > 0)
                    maxGold = max(maxGold, dfs(i, j, m, n, grid));

        return maxGold;
    }
}; 
    

int main() {
    fastio();
    
    return 0;
}