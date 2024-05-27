/* Debjyoti Ghosh*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define INF 2e18
#define PI 3.1415926535897932384626
#define mod 998244353
#define f first
#define s second 

double eps = 1e-12;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void google(int t) {cout << "Case #" << t << ": ";}
    
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;

        // every 1 min = 1 level in graph traversal
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    grid[i][j] = 0;
                }
            }
        }

        vector<vector<bool>>vis(m,vector<bool>(n,false));
        while(!q.empty()){
            auto xy = q.front();
            q.pop();
            int i = xy.first, j = xy.second;

            int dx[] = {1,-1,0,0};
            int dy[] = {0,0,1,-1};

            for(int k=0; k<4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]
                    && grid[nx][ny] == 1){
                    vis[nx][ny] = true;
                    grid[nx][ny] = 1 + grid[i][j];
                    q.push({nx,ny});
                }
            }
        }

        int mins = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !vis[i][j])
                    return -1;
                
                else if(grid[i][j] != 0)
                    mins = max(mins, grid[i][j]);
            }
        }
        return mins;
    }
};   


// solution without using visited grid
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;

        // every 1 min = 1 level in graph traversal
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    grid[i][j] = 0;
                }
                else if(grid[i][j] == 1)
                    grid[i][j] = -1;
            }
        }

        while(!q.empty()){
            auto xy = q.front();
            q.pop();
            int i = xy.first, j = xy.second;

            int dx[] = {1,-1,0,0};
            int dy[] = {0,0,1,-1};

            for(int k=0; k<4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny] == -1){
                    grid[nx][ny] = 1 + grid[i][j];
                    q.push({nx,ny});
                }
            }
        }

        int mins = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == -1)
                    return -1;
                
                else if(grid[i][j] != 0)
                    mins = max(mins, grid[i][j]);
            }
        }
        return mins;
    }
};   


int main() {
    fastio();
    
    return 0;
}