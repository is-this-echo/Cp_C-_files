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
    int snakesAndLadders(vector<vector<int>>& board)
    {
        int n = board.size();

        int k = 1;
        vector<int> flatBoard(n*n + 1, -1);
        bool isLeftToRight = true;
        for (int row = n - 1; row >= 0; --row)
        {
            if (isLeftToRight)
            {
                for (int col = 0; col < n; ++col)
                    flatBoard[k++] = board[row][col];
            }
            else
            {
                for (int col = n - 1; col >= 0; --col)
                    flatBoard[k++] = board[row][col];
            }
            isLeftToRight = !isLeftToRight;
        }

        vector<vector<int>> graph(n*n + 1); // nodes are from 1 to n*n
        // create adjacency list for all nodes except the nth node
        // as it will lead to overflow from board
        for (int  node = 1; node < n * n; ++node)
        {
            for (int dice = 1; dice <= 6; ++dice)
            {
                int dest = node + dice;
                if (dest <= n*n)
                {
                    if (flatBoard[dest] != -1)
                        dest = flatBoard[dest];

                    graph[node].emplace_back(dest);
                }
            }
        }

        // do bfs traversal
        vector<int>dis(n*n + 1, 0);
        vector<bool> vis(n*n + 1, false);
        queue<int> q;

        q.push(1);
        vis[1] = true;
        dis[1] = 0;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto nbr : graph[curr])
            {
                if (!vis[nbr])
                {
                    q.push(nbr);
                    vis[nbr] = true;
                    dis[nbr] = 1 + dis[curr];
                }
            }
        }
        return dis[n*n] ? dis[n*n] : -1;

    }
};


int main() {
    fastio();
    
    return 0;
}