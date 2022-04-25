#include<iostream>
#include<cstring>
#include<climits>
#include<vector>
using namespace std;


int cherryPickup(vector<vector<int>> &grid, int r1, int c1, int c2, int n,int dp[][50][50]){
    int r2 = r1+c1-c2;

    if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
        return INT_MIN;

    if(dp[r1][c1][c2]!=-1)
        return dp[r1][c1][c2];
    
    if(r1==n-1 && c1 ==n-1)
        return grid[r1][c1];
    
    int ans = grid[r1][c1];
    if(c1!=c2)
        ans+=grid[r2][c2];
    
    int temp = max(cherryPickup(grid,r1,c1+1,c2+1,n,dp),cherryPickup(grid,r1+1,c1,c2+1,n,dp));
    temp = max(temp, cherryPickup(grid,r1,c1+1,c2,n,dp));
    temp = max(temp,cherryPickup(grid,r1+1,c1,c2,n,dp));

    ans+=temp;
    return dp[r1][c1][c2] = ans;
}



int main()
{   int dp[50][50][50];
    vector<vector<int>> matrix = {{0,1,-1},{1,0,-1},{1,1,1}};
    int n = matrix.size();
    memset(dp,-1,sizeof(dp));

    cout<<max(0,cherryPickup(matrix, 0,0,0,n,dp));
    
    return 0;
}