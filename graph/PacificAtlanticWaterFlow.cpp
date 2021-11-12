// Leetcode 417

#include<iostream>
#include<vector>
using namespace std;

#define ll long long
#define mod 998244353

double eps = 1e-12;

// TC = O(nxm)
// SpaceC = O(nxm)
void dfs(vector<vector<int>>&grid, vector<vector<int>>&visited, int i,int j, int m, int n, int height){
    if(i>=0 && i<m && j>=0 && j<n && !visited[i][j] && grid[i][j]>=height){
        visited[i][j]=1;

        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        for(int k=0;k<4;k++){
            int cx = i+dx[k];
            int cy = j + dy[k];
            dfs(grid,visited,cx,cy,m,n,grid[i][j]);
        }
    }
    else 
        return;
}


vector<vector<int>> pacificAtlantic(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> pac(m,vector<int>(n,0));
    vector<vector<int>> atl(m,vector<int>(n,0));

    for(int col=0;col<n;col++){
        dfs(grid,pac,0,col,m,n,grid[0][col]);
        dfs(grid,atl,m-1,col,m,n,grid[m-1][col]);
    }

    for(int row=0;row<m;row++){
        dfs(grid,pac,row,0,m,n,grid[row][0]);
        dfs(grid,atl,row,n-1,m,n,grid[row][n-1]);
    }

    vector<vector<int>> ans;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(pac[i][j]==1 && atl[i][j]==1)
                ans.push_back({i,j});
        }
    }

    return ans;
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<vector<int>> island = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};

    auto x = pacificAtlantic(island);

    for(auto i : x){
        for(auto j : i)
            cout<<j<<" ";
        cout<<"\n";
    }

    return 0;
}