
// leetcode 695. Max Area of Island

#include<iostream>
#include<vector>
using namespace std;


int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int m, int n, int i, int j){
    visited[i][j]=true;
    int csize =1;

    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};

    for(int k=0;k<4;k++){
        int nx= i + dx[k];
        int ny= j + dy[k];
 
        if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny] && grid[nx][ny]==1){
            int subComponent = dfs(grid,visited,m,n,nx,ny);
            csize += subComponent;
        }
    }
    return csize;
}


int largest_island(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n,false));
    int largestSize=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && grid[i][j]==1){
                int size = dfs(grid,visited,m,n,i,j);
                if(size>largestSize)
                    largestSize=size;
            }
        }
    }
    return largestSize;
}



int main()
{   vector<vector<int>> grid={{1,0,0,1,0},
                              {1,0,1,0,0},
                              {0,0,1,0,1},
                              {1,0,1,1,1},
                              {1,0,1,1,0}};
    
    cout<<largest_island(grid);

    return 0;
}