
// 542. 01 Matrix


#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
    
 // multi-source bfs
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    queue<pair<int,int>>q;
        
    int m = mat.size();
    int n = mat[0].size();
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0)
                q.push({i,j});
            else
                mat[i][j]=-1;
        }
    }
    
    while(!q.empty()){
        auto p = q.front();
        int i = p.first, j = p.second;
        q.pop();
        
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        for(int k=0;k<4;k++){
            int cx = i + dx[k];
            int cy = j + dy[k];
            
            if(cx>=0 && cx<m && cy>=0 && cy<n && mat[cx][cy]==-1){
                mat[cx][cy] = 1 + mat[i][j];
                q.push(make_pair(cx,cy));
            }
        }
    }
    
    return mat;
}


void print(vector<vector<int>>&mat){
    for(auto x: mat){
        for(auto y : x)
            cout<<y<<" ";
        cout<<"\n";
    }
    cout<<"\n\n";
}

    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    vector<vector<int>>grid = {{0,0,0},{0,1,0},{1,1,1}};

    print(grid);
    updateMatrix(grid);
    print(grid);
    
    return 0;
}