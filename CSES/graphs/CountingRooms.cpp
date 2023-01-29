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
 
 
void dfs(vector<vector<char>>&grid, vector<vector<bool>>&vis, int i, int j, int n, int m){
    vis[i][j] = true;
 
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
 
    for(int k=0;k<4;k++){
        int nx = i + dx[k];
        int ny = j + dy[k];
 
        if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]=='.'){
            dfs(grid,vis,nx,ny,n,m);
        }
    }
}
 
 
void solve(){
    int n,m;
    cin>>n>>m;
 
    vector<vector<char>>grid(n, vector<char>(m,'.'));
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
 
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    int ans = 0;
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.' && !vis[i][j]){
                dfs(grid,vis,i,j,n,m);
                ans++;
            }
        }
    }
    cout<<ans;
}
 
 
int main() {
    fastio();
 
    solve();
 
    return 0;
}