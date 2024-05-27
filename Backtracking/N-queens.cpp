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
#define f first
#define s second 

double eps = 1e-12;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void google(int t) {cout << "Case #" << t << ": ";}



// Leetcode 51. N-Queens
void rec(int row, int n, vector<int>&placed, vector<vector<string>>&board){
    if(row==n){
        vector<string>temp;
        string s;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==placed[i])
                    s.push_back('Q');
                else
                    s.push_back('.');
            }

            temp.push_back(s);
            s.erase();

        }
        board.push_back(temp);
        return;
    }

    for(int col=0; col<n; col++){
        bool isSafe = true;

        for(int pRow = 0; pRow<row; pRow++){
            int pCol = placed[pRow];

            if(col == pCol || abs(pRow-row)==abs(pCol-col)){
                isSafe = false;
            }
        }
        if(isSafe){
            placed.push_back(col);
            rec(row+1, n, placed, board);
            placed.pop_back();
        }
    }

}


void solveNQueens(int n, vector<int>&placed, vector<vector<string>>&board) {
    rec(0, n, placed, board);
}


int main() {
    fastio();

    vector<int>placed;
    vector<vector<string>>board;

    int n;
    cin>>n;

    solveNQueens(n, placed, board);

    for(auto i : board){
        for(auto j : i)
            cout<<j;
        cout<<"\n";
    }

    return 0;
}