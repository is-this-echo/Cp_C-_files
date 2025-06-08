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
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> q;

        // Push all border 'O's into the queue for BFS
        for (int i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O')
                q.push({i, 0});

            if (board[i][n - 1] == 'O')
                q.push({i, n - 1});
        }

        for (int j = 0; j < n; ++j)
        {
            if (board[0][j] == 'O')
                q.push({0, j});

            if (board[m - 1][j] == 'O')
                q.push({m - 1, j});
        }

        // Mark all connected 'O's starting from the border
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O')
                continue;

            board[x][y] = 'T';

            for (int k = 0; k < 4; ++k)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                q.push({nx, ny});
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                else if (board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};


int main() {
    fastio();
    
    return 0;
}