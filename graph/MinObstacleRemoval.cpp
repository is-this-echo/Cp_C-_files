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


// Using Djjikstra's approach, assume cells with obstacle (value = 1) to be
// a weighted edge and empty cells with 0 weight.
// A distance grid is required as we are trying to find the minimum obstacle
// removals from (0,0) to all the cells in the grid.
class Solution
{
public:
    int minimumObstacles(vector<vector<int>>& grid)
    {   
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<
        std::tuple<int,int,int>,
        std::vector<std::tuple<int,int,int>>,
        greater<>> pq;

        pq.emplace(0, 0, 0);
        dist[0][0] = 0;

        vector<int> dx{0, 0, 1, -1};
        vector<int> dy{1, -1, 0, 0};

        while (!pq.empty())
        {
            auto [currDist, x, y] = pq.top();
            pq.pop();

            // if the distance to this node at (x,y) is
            // greater than what's already in the dist grid
            // don't explore this path
            if (currDist > dist[x][y])
                continue;
            
            for (int k = 0; k < 4; ++k)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                int cost = currDist + grid[nx][ny];
                if (cost < dist[nx][ny])
                {
                    dist[nx][ny] = cost;
                    pq.emplace(cost, nx, ny);
                }
            }
        }
        return dist[m-1][n-1];
    }
};


// Using 0-1 BFS concept with deque.
class Solution
{
public:
    int minimumObstacles(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<std::pair<int,int>> dq;

        dist[0][0] = 0;
        dq.push_front({0, 0});

        vector<int> dx{0, 0, 1, -1};
        vector<int> dy{1, -1, 0, 0};

        while (!dq.empty())
        {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int k = 0; k < 4; ++k)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                
                int cost = grid[nx][ny];

                if (dist[x][y] + cost < dist[nx][ny])
                {
                    dist[nx][ny] = dist[x][y] + cost;

                    if (cost == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }
        return dist[m-1][n-1];
    }
};

    
int main()
{
    fastio();

    return 0;
}
