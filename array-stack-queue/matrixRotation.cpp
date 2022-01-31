#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

#define ll long long
#define mod 1e9+7


bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
/*  boolean array 0idx = 0 or 360 rotation
    1idx  = 90deg,  2idx = 180deg, 3idx = 270deg
*/
    bool r[4]={true};
    int n = mat.size();
    
    memset(r,true,sizeof(r));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            if(mat[i][j]!=target[i][j]) r[0] = false;
            
            if(mat[i][j]!=target[j][n-i-1]) r[1] = false;
            
            if(mat[i][j]!=target[n-i-1][n-j-1]) r[2] = false;
            
            if(mat[i][j]!=target[n-j-1][i]) r[3] = false;
        }
    }
    
    return r[0] || r[1] || r[2] || r[3];
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}}, 
                        target = {{1,1,1},{0,1,0},{0,0,0}};

    cout<<findRotation(mat,target);
    
    return 0;
}