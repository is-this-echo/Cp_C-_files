#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;


// 827. Making A Large Island 
// Create a map with each unique island_id and its size using dfs traversal
//  Next, traverse the matrix once more to find zeros and add the neighboring size
// of islands as that cell were 1.

class Solution {
    // (islandNo, size of island)
    unordered_map<int,int>mp;
    
public:
    
    void dfs(vector<vector<int>>&grid, int m, int n, int islandNo,
            int i, int j){
        
        if(i>=0 && i<m && j>=0 && j<n && grid[i][j]==1){
            grid[i][j] = islandNo;          
            mp[islandNo]++;
            
            int dx[] = {0,0,1,-1};
            int dy[] = {1,-1,0,0};
            
            for(int k=0;k<4;k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                
                dfs(grid,m,n,islandNo,nx,ny);
            }
            
        }
    }
    
    void helper(vector<vector<int>>&grid,unordered_set<int>&st, int i, int j,
               int m, int n){
        
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        for(int k=0;k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]!=0)
                st.insert(grid[nx][ny]);
        }
    }
    
    
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int islandNo = 2;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    dfs(grid,m,n,islandNo,i,j);
                islandNo++;
            }
        }
        
        int largest = 0;
        unordered_set<int>st;
        
        for(auto pairVal : mp){
            largest = max(largest,pairVal.second);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count=1;
                
                if(grid[i][j]==0){
                    helper(grid,st,i,j,m,n);
                    for(auto num : st){
                        count += mp[num];
                    }
                    largest = max(largest, count);
                    st.clear();
                }
            }
        }
        
        return largest;
    }
};


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<vector<int>> grid = {{1,1}, {1,0}};

    Solution sol;

    cout<<sol.largestIsland(grid);

    
    return 0;
}