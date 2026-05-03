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
    int swimInWater(vector<vector<int>>& grid)
    {
        int n = grid.size();
        std::priority_queue<
            std::tuple<int,int,int>,
            vector<std::tuple<int,int,int>>,
            greater<>> pq;  // time to reach, x, y

        std::unordered_set<int> visited;

        int ans = 0;
        pq.emplace(grid[0][0], 0, 0);
        visited.insert(grid[0][0]);

        std::vector<int> dx{0, 0, 1, -1};
        std::vector<int> dy{1, -1, 0, 0};

        while (!pq.empty())
        {
            auto [timeToReach, x, y] = pq.top();
            pq.pop();

            ans = max(ans, timeToReach);

            if (x == n - 1 && y == n - 1)
                return ans;

            for (int k = 0; k < 4; ++k)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n ||
                    visited.find(grid[nx][ny]) != visited.end())
                    continue;

                pq.emplace(grid[nx][ny], nx, ny);
                visited.insert(grid[nx][ny]);
            }

        }

        return ans;
    }
};



int main()
{
    fastio();
    
    return 0;
}