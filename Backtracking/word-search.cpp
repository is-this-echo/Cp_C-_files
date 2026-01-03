#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
const double eps = 1e-12;


// leetcode 79. Word Search
// Time complexity = O(m*n*4^(word length))

bool dfs(vector<vector<char>>&board, string word, int row, int col, int i,
    int m, int n, vector<vector<bool>>&vis){

    if(i==word.length())
        return true;

    if(row<0 || col<0 || row>=m || col>=n || board[row][col]!=word[i]
        || vis[row][col])
        return false;

    vis[row][col]=true;

    bool ans = (dfs(board,word,row-1,col,i+1,m,n,vis) ||
                dfs(board,word,row,col+1,i+1,m,n,vis) ||
                dfs(board,word,row+1,col,i+1,m,n,vis) ||
                dfs(board,word,row,col-1,i+1,m,n,vis));

    vis[row][col]=false;
    return ans;
}


bool exist(vector<vector<char>> &board, string word) {
    int m=board.size(),n=board[0].size();
    vector<vector<bool>>vis(m,vector<bool>(n,false));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dfs(board,word,i,j,0,m,n,vis))
                return true;
        }
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    return 0;
}