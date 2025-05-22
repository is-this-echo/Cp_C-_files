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
    int countServers(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        // precompute server locations, todo: save memory by using bool
        vector<int> serverRowPos(rows, 0);
        vector<int> serverColPos(cols, 0);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == 1)
                {
                    serverRowPos[i] += 1;
                    serverColPos[j] += 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (grid[i][j] == 1 && (serverRowPos[i] > 1 || 
                                        serverColPos[j] > 1))
                    ans++;

        return ans;
    }
};


int main() {
    fastio();
    
    return 0;
}