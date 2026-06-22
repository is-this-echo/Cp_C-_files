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
    
 
// Recursive solution with exponential time complexity and O(n x 2 x 3) space
class Solution
{
    int profit(int idx, bool buy, int cap, vector<int>& prices)
    {
        if (idx == prices.size() || cap == 0)
            return 0;
        
        if (buy)
            return max( -prices[idx] + profit(idx + 1, false, cap, prices),
                        0 + profit(idx + 1, true, cap, prices));

        return max( prices[idx] + profit(idx + 1, true, cap - 1, prices),
                    0 + profit(idx + 1, false, cap, prices));
    }

public:
    int maxProfit(vector<int>& prices)
    {
        // idx : 0 -> n
        // buy : true / false
        // cap : 0 or 1 or 2
        return profit(0, true, 2, prices);
    }
};


// DP solution TC = O(nx2x3) and SC = O(nx2x3) + O(n) call stack
class Solution
{

    int profit(int idx, int buy, int cap, vector<int>& prices,
                vector<vector<vector<int>>>& dp)
    {
        if (idx == prices.size() || cap == 0)
            return 0;

        if (dp[idx][buy][cap] != -1)
            return dp[idx][buy][cap];

        if (buy)
            return dp[idx][buy][cap] = 
                    max( -prices[idx] + profit(idx + 1, false, cap, prices, dp),
                        0 + profit(idx + 1, true, cap, prices, dp));

        return dp[idx][buy][cap] = 
                max( prices[idx] + profit(idx + 1, true, cap - 1, prices, dp),
                    0 + profit(idx + 1, false, cap, prices, dp));
    }

public:
    int maxProfit(vector<int>& prices)
    {
        // idx : 0 -> n
        // buy : true / false
        // cap : 0 or 1 or 2
        // dp[idx][buy][cap] -> max profit at idx with buy and cap max txns
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,
                                vector<vector<int>>(2, vector<int>(3, -1)));

        return profit(0, 1, 2, prices, dp);
    }
};



int main()
{
    fastio();
    
    return 0;
}
