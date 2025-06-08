#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;


// DFS solution
int dfs(vector<vector<int>>&grid, vector<vector<bool>>&vis, int m, int n, int i, int j){
    // if dfs call goes out of bounds or to a cell with water
    if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0)
        return 1;

    // if cell is visited
    if(vis[i][j])
        return 0;

    // if cell is not visited
    vis[i][j]=1;

    int perimeter = 0;
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};

    for(int k=0;k<4;k++){
        perimeter += dfs(grid,vis,m,n,i+dx[k],j+dy[k]);
    }
    return perimeter;
}

int islandPerimeter(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int ans;

    vector<vector<bool>>vis(m,vector<bool>(n,false));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && !vis[i][j])
                    ans = dfs(grid,vis,m,n,i,j);
                    break;
        }
    }
    return ans;
} 

// BFS solution
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int startRow, startCol;

        bool foundLand = false;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    startRow = i;
                    startCol = j;
                    foundLand = true;
                    break;
                }
            }
            if (foundLand)
                break;
        }

        vector<vector<bool>> vis(m,vector<bool>(n,false));
        queue<pair<int,int>> q;

        q.push({startRow, startCol});
        vis[startRow][startCol] = true;

        int perimeter = 0;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();

            for (int k = 0; k < 4; ++k)
            {
                int nx = row + dx[k];
                int ny = col + dy[k];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 0)
                    perimeter += 1;
                
                else if (!vis[nx][ny])
                {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
        return perimeter;
    }
};


// Using grid geometry and loops
int islandPerimeter(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), perim = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                perim += 4;
                if (i+1 < m && grid[i+1][j] == 1) perim -= 2;
                if (j+1 < n && grid[i][j+1] == 1) perim -= 2;
            }
        }
    }
    return perim;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};

    cout<<islandPerimeter(grid);
    
    return 0;
}