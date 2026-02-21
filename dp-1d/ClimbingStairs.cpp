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




// Top-down approach
class Solution
{
    int helper(int n, vector<int>& dp)
    {
        if (n < 0)
            return 0;

        if (n == 0)
            return 1;

        if (dp[n] != 0)
            return dp[n];

        return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    }

public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, 0);
        return helper(n, dp);
    }
};


// Bottom-up approach
class Solution
{
public:
    int climbStairs(int n)
    {
        // dp[i] -> number of distinct ways by which we can reach the 
        // ith  staircase starting from 0th staircase. dp(n) is the answer.
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};


int main()
{
    fastio();
    
    return 0;
}