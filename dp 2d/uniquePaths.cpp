// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

// grid without obstacle
int uniquePaths(int m, int n){
    vector<vector<int>> dp(m,vector<int>(n,0));

    for(int i=0;i<m;i++)
        dp[i][0]=1;

    for(int i=0;i<n;i++)
        dp[0][i]=1;

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    return dp[m-1][n-1];
}


// grid with obstacles
int uniquePaths2(vector<vector<int>> &ObstacleGrid){
    int m = ObstacleGrid.size();
    int n = ObstacleGrid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));

    if(ObstacleGrid[0][0]==1 || ObstacleGrid[m-1][n-1]==1)
        return 0;

    dp[0][0]=1;

    for(int i=1;i<n;i++){
        if(ObstacleGrid[0][i]==1 || dp[0][i-1]==0)
            dp[0][i]=0;

        else dp[0][i]=1;
    }

    for(int j=1;j<m;j++){
        if(ObstacleGrid[j][0]==1 || dp[j-1][0]==0)
            dp[j][0]=0;

        else dp[j][0]=1;
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(ObstacleGrid[i][j]==1)
                dp[i][j]=0;
            else
                dp[i][j]= dp[i][j-1] + dp[i-1][j];
        }
    }
    return dp[m-1][n-1];
}



int main()
{
    int m=3,n=2;
    vector<vector<int>> sampleGrid={{0,0,0},{0,1,0},{0,0,0}};

    cout<<"The number of unique paths from top left to bottom right is: "<<uniquePaths(m,n);
    cout<<endl;
    cout<<"The number of unique paths from top left to bottom right is: "<<uniquePaths2(sampleGrid);
   
    return 0;
}