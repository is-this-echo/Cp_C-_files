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



class Solution
{
public:
    int shortestPath(vector<vector<int>>& grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        // visited[i][j] stores the number of obstacles we can still remove
        // after walking cell (i,j)
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<vector<int>> q;
        q.push({0, 0, 0, k});

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            int x = curr[0], y = curr[1];
            int steps = curr[2];
            int canRemove = curr[3];

            // we can do this while pushing elements to queue itself
            if (x < 0 || x >= m || y < 0 || y >= n)
                continue;

            if (x == m - 1 && y == n - 1)
                return steps;

            if (grid[x][y] == 1)
            {
                if (canRemove > 0)
                    canRemove--;
                else
                    continue;
            }

            if (visited[x][y] != -1 && visited[x][y] >= canRemove)
                continue;

            visited[x][y] = canRemove;

            q.push({x + 1, y, steps + 1, canRemove});
            q.push({x - 1, y, steps + 1, canRemove});
            q.push({x, y + 1, steps + 1, canRemove});
            q.push({x, y - 1, steps + 1, canRemove});
        }
        return -1;
    }
};



int main()
{
    fastio();
    
    return 0;
}
