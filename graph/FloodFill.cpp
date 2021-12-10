#include<iostream>
#include<vector>
using namespace std;

#define ll long long
#define mod 998244353
double eps = 1e-12;
    

 void dfs(vector<vector<int>>&grid, int i, int j, int m, int n, int newCol, int                prevCol){    
    if(i>=0 && i<m && j>=0 && j<n && grid[i][j]==prevCol){
        grid[i][j] = newCol;
        
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        for(int k=0;k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];

            dfs(grid,nx,ny,m,n,newCol,prevCol);
        }
    } 
}
        
    
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newCol) {
    vector<vector<int>> grid = image;
    int m = grid.size();
    int n = grid[0].size();
    int prevCol =image[sr][sc]; 
    
    // this check is necessary to prevent overflow, think about it
    if(prevCol!=newCol)
        dfs(grid,sr,sc,m,n,newCol,prevCol);
    
    return grid;
}


void printGrid(vector<vector<int>>&grid){
    for(auto i : grid){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    vector<vector<int>> matrix = {{1,1,1},{1,1,0},{1,0,1}};
    int newColor = 2;
    int sr = 1, sc =1;
    printGrid(matrix);

    auto newMatrix = floodFill(matrix,sr,sc,newColor);
    printGrid(newMatrix);

    
    return 0;
}