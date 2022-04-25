#include<iostream>
#include<vector>
#include<climits>
#include<map>
using namespace std;


class pothole{
    public:
    int px;
    int py;
    int pt;

    pothole(int a, int b, int c){
        py=a,px=b,pt=c;
    }
};

// dp grid stores min. time elapsed to visit cell(x,y)
int Alphonso(vector<vector<int>> grid, int y, int x, map<pair<int,int>,int> ph ){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));

    dp[0][0]=1;

    for(int i=1;i<n;i++){
        if(grid[0][i]==1 || dp[0][i-1]==INT_MAX)
            dp[0][i]=INT_MAX;

        else //if(dp[0][i-1]!=ph[{0,i}])
            dp[0][i]=dp[0][i-1]+1;
    }

    for(int j=1;j<m;j++){
        if(grid[j][0]==1 || dp[j-1][0]==INT_MAX)
            dp[j][0]=INT_MAX;

        else //if(dp[j-1][0]!=ph[{j,0}])
            dp[j][0]=dp[j-1][0]+1;
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(grid[i][j]==1)
                dp[i][j]=INT_MAX;

            else if(dp[i-1][j]!=ph[{i,j}] || dp[i][j-1]!=ph[{i,j}])
                dp[i][j]=min(dp[i][j-1], dp[i-1][j])+1;
        }
    }
    return dp[x-1][y-1];

}


int main()
{
    int y,x;
    y=2,x=3;

    vector<vector<int>> grid = {{0,0,0,0,0},{0,1,0,0,0},{0,0,0,0,0}};
    // vector<pothole> p = {pothole(1,3,1)};
    map<pair<int,int>,int> m;

    // given input is a pothole will be created at (3,1) {1-indexed} at t=1min
    m[{2,0}]=2; 

    // m[{1,0}]=1;
    // m[{0,1}]=2;
    cout<<"The minimum time required is: "<<Alphonso(grid,y,x,m);

    return 0;
}