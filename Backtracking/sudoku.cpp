
// 37. Sudoku Solver

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
const double eps = 1e-12;
    

bool canFill(vector<vector<char>>&board, int row, int col, char ch){
    for(int i=0;i<9;i++){
        if(board[row][i]==ch)
            return false;
            
        if(board[i][col]==ch)
            return false;
        
        if(board[3*(row/3) + i/3][3*(col/3) + i%3]==ch)
            return false;
    }
    return true;
}


bool sudokuSolver(vector<vector<char>>&board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            
            if(board[i][j]=='.'){

                for(char ch='1';ch<='9';ch++){
                    
                    if(canFill(board,i,j,ch)){
                        board[i][j] = ch;
                
                        if(sudokuSolver(board)==true)
                            return true;
                        
                        else
                            board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }

    return true;
}



void solveSudoku(vector<vector<char>>& board) {
    sudokuSolver(board);
}
    

void printSudoku(vector<vector<char>>&board){
    for(auto x: board){
        for(auto y : x)
            cout<<y<<" ";
        cout<<"\n";
    }
    cout<<"\n\n";
}


    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<vector<char>> sudoku =  {{'5','3','.','.','7','.','.','.','.'},
                                    {'6','.','.','1','9','5','.','.','.'},
                                    {'.','9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},
                                    {'4','.','.','8','.','3','.','.','1'},
                                    {'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},
                                    {'.','.','.','4','1','9','.','.','5'},
                                    {'.','.','.','.','8','.','.','7','9'}};

    printSudoku(sudoku);
    solveSudoku(sudoku);
    printSudoku(sudoku);

    return 0;
}