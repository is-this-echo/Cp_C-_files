#include<iostream>
#include<vector>
using namespace std;


int dfs(vector<vector<int>>&grid, vector<vector<int>>&dp, int m, int n, int i, int j){
    if(dp[i][j]!=0)
        return dp[i][j];
    
// else it means dp[i][j] is 0, or we dont have the longest path from that starting node
    dp[i][j]=1;
    
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    
    for(int k=0;k<4;k++){
        int cx = i + dx[k];
        int cy = j + dy[k];
        
        if(cx>=0 && cx<m && cy>=0 && cy<n){
            if(grid[cx][cy]>grid[i][j])
                dp[i][j] = max(dp[i][j], dfs(grid,dp,m,n,cx,cy)+1);
        }
    }
    return dp[i][j];
}

    
    
void longestIncreasingPath(vector<vector<int>>& matrix) {    
// dfs from each cell, taking it as start node
//  dp[i][j], 2 states to denote longest increasing path from node at (i,j)
    
    int m = matrix.size();
    int n = matrix[0].size();
    
    vector<vector<int>> dp(m,vector<int>(n,0));
    int ans = 1;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ans = max(ans,dfs(matrix,dp,m,n,i,j));
        }
    }

    for(auto x: dp){
        for(auto y: x)
            cout<<y<<" ";
        cout<<"\n";
    }

    cout<<"Longest increasing path is "<<ans;
   
}




int main()
{
    vector<vector<int>> grid = {{9,9,4},{6,6,8},{2,1,1}};
  
    longestIncreasingPath(grid);

    return 0;
}