/* Debjyoti Ghosh*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void google(int t) {cout << "Case #" << t << ": ";}
    
 
class Solution {
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
public:
    
    bool isValid(int n, int i, int j){
        // return true if cell is within grid bounds
        return (i>=0 && i<n && j>=0 && j<n);
    }
    
    
    void dfs(vector<vector<int>>&grid, int n, int i, int j,
            queue<pair<int,int>>&q, vector<vector<bool>>&vis){
        
        // base case
        if(!isValid(n,i,j) || vis[i][j] || grid[i][j]==0)
            return;
        
        // push cell to queue for bfs
        vis[i][j] = true;
        q.push({i,j});
            
        for(int k=0;k<4;k++){
            
            int cx = i + dx[k];
            int cy = j + dy[k];
            
            dfs(grid,n,cx,cy,q,vis);
        }
    }
    
    
    int bfs(vector<vector<int>>&grid, vector<vector<bool>>&vis,
            queue<pair<int,int>>&q){
        
        int ans = 0, n = grid.size();
        
        while(!q.empty()){
            // for loop ends after each layer is completed
            // even if queue size changes, the size in for loop remains same
            int len = q.size();
            
            for(int i=0;i<len;i++){
                pair<int,int>p = q.front();

                q.pop();
                
                for(int k=0;k<4;k++){
                    int cx = p.first + dx[k];
                    int cy = p.second + dy[k];
                    
                    if(!isValid(n,cx,cy) || vis[cx][cy])
                        continue;
                    
                    if(grid[cx][cy]==1)
                        return ans;
                    
                    vis[cx][cy] = true;
                    q.push({cx,cy});
                }

            }
            ans++;
        }
        return ans;
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {

        int n = grid.size();
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(grid,n,i,j,q,vis);
                    return bfs(grid,vis,q);
                }
                    
            }
        }
        return 0;
    }
};


int main() {
    fastio();

    vector<vector<int>>grid = {{0,1,0},{0,0,0},{0,0,1}};

    Solution sl;
    cout<<sl.shortestBridge(grid)<<"\n";

    return 0;
}