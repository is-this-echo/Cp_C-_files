
// leetcode : 221. Maximal Square

#include<iostream>
#include<vector>
using namespace std;

#define ll long long
#define mod 998244353
double eps = 1e-12;
    

 // TC = O(mn), SC = O(mn)    
    
int dfs(vector<vector<char>>&grid, vector<vector<int>>&dp, int i, int j, int rows, int cols){  
    if(i>=rows || j>=cols)
        return 0;
    
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    dp[i][j] =0;
    int down = dfs(grid,dp,i+1,j,rows,cols);
    int right = dfs(grid,dp,i,j+1,rows,cols);
    int diag = dfs(grid,dp,i+1,j+1,rows,cols);
    
    if(grid[i][j]=='1'){
        dp[i][j] = 1 + min(down,min(right,diag));
    }
    
    return dp[i][j];
}
    


int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>>dp(m,vector<int>(n,-1));
    
    dfs(matrix,dp,0,0,m,n);
    int ans=0;
    
    for(auto x: dp)
        for(auto y: x)
            ans=max(ans,y);
    
    return ans*ans;
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},
                                  {'1','1','1','1','1'},{'1','0','0','1','0'}};
    
    cout<<maximalSquare(matrix);

    return 0;
}