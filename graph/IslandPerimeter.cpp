#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
 

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



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};

    cout<<islandPerimeter(grid);
    
    return 0;
}