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
    
 
// Time complexity = O(abs(x-y)), we linearly travel from x to y, if
// the division operations are applied, we arrive much faster.
class Solution
{
public:
    int minimumOperationsToMakeEqual(int x, int y)
    {
        // x -> y
        std::queue<pair<int,int>> q; // number, turns to reach
        q.emplace(x, 0);

        std::unordered_set<int> vis;
        vis.insert(x);

        while (!q.empty())
        {
            auto [currNum, turns] = q.front();
            q.pop();

            if (currNum == y)
                return turns;

            if (currNum % 11 == 0 && vis.find(currNum / 11) == vis.end())
            {
                q.emplace(currNum / 11, turns + 1);
                vis.insert(currNum / 11);
            }

            if (currNum % 5 == 0 && vis.find(currNum / 5) == vis.end())
            {
                q.emplace(currNum / 5, turns + 1);
                vis.insert(currNum / 5);
            }

            if (vis.find(currNum + 1) == vis.end())
            {
                q.emplace(currNum + 1, turns + 1);
                vis.insert(currNum + 1);
            }

            if (vis.find(currNum - 1) == vis.end() && currNum - 1 >= 1)
            {
                q.emplace(currNum - 1, turns + 1);
                vis.insert(currNum - 1);
            }
        }

        return -1;
    }
};


int main() {
    fastio();
    
    return 0;
}