
//36. Valid Sudoku
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
const double eps = 1e-12;
    

 
bool isValidSudoku(vector<vector<char>>& board) {
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            
            if(board[i][j]!='.'){
                bool res = canFill(board,i,j,board[i][j]);
                
                if(!res) return false;
            }   
        }
    }
    return true;
}
    
    
bool canFill(vector<vector<char>>&board, int row, int col,char ch){
    int cnt=0;
    
    for(int i=0;i<9;i++){
        if( board[row][i]==ch)
            cnt++;
        
        if(board[i][col]==ch)
            cnt++;
        
        if(board[3*(row/3) + i/3][3*(col/3) + i%3]==ch)
            cnt++;;
        
    }
    return cnt>3 ? false : true;
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    
    
    return 0;
}