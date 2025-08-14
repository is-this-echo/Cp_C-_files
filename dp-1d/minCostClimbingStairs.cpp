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


/*
    dp[i] -> minimum cost to reach ith step from 0th staircase
    dp[i] = cost[i] + min(dp[i-1], dp[i-2]))

    So, here our goal is to reach the (n-1)th or (n-2) th step and from
    here we can easily reach the nth step.
*/
// Top-down approach
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1); // memoization array

        // Recursive function with memoization
        function<int(int)> minCost = [&](int i) -> int {
            if (i < 0) return 0;
            if (i == 0 || i == 1) return cost[i];
            if (dp[i] != -1) return dp[i];

            return dp[i] = cost[i] + min(minCost(i - 1), minCost(i - 2));
        };

        // Final step is just beyond the last index
        return min(minCost(n - 1), minCost(n - 2));
    }
};

// Bottom-up approach
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; ++i)
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);

        return min(dp[n - 1], dp[n - 2]);
    }
};

// Space-optimized approach
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int first = cost[0], second = cost[1];

        for (int i = 2; i < n; ++i) {
            int current = cost[i] + min(first, second);
            first = second;
            second = current;
        }

        return min(first, second);
    }
};


/*
    dp[i] -> minimum cost to reach the top from the ith step
    dp[i] = cost[i] + min(dp[i+1], dp[i+2]))

    Here, we need to find the minimum cost to reach top from
    the 1st or 2nd step i.e. dp[0] or dp[1].
*/

// Top-down approach
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1); // dp[n] = 0 (top floor)

        function<int(int)> dfs = [&](int i) -> int {
            if (i >= n) return 0; // Reached or passed top
            if (dp[i] != -1) return dp[i];
            return dp[i] = cost[i] + min(dfs(i + 1), dfs(i + 2));
        };

        return min(dfs(0), dfs(1));
    }
};

// Bottom-up approach
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 2, 0); // dp[n] = 0 is the top

        for (int i = n - 1; i >= 0; --i)
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);

        return min(dp[0], dp[1]);
    }
};

// Space-optimized approach
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int next1 = 0, next2 = 0;

        for (int i = n - 1; i >= 0; --i) {
            int current = cost[i] + min(next1, next2);
            next2 = next1;
            next1 = current;
        }

        return min(next1, next2);
    }
};



int main()
{
    fastio();
    
    return 0;
}