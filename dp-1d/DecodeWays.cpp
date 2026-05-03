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

// Recursive approach, O(2^n) time and O(n) space complexity for recursion stack
class Solution
{
int solve(int idx, const string& str, int n)
{
    // valid string found
    if (idx == n)
        return 1;

    if (str[idx] == '0') // split not possible further
        return 0;

    int ans = solve(idx + 1, str, n);

    if (idx + 1 < n)
    {
        if (str[idx] == '1' || (str[idx] == '2' && str[idx + 1] <= '6'))
            ans += solve(idx + 2, str, n);
    }

    return ans;
}

public:
    int numDecodings(string s)
    {
        return solve(0, s, s.length());
    }
};


// Top-down approach, O(n) time as each state is calculated only once
// O(n) space for dp vector and recursion stack
class Solution
{

int solve(int idx, const string& str, int n, vector<int>& dp)
{
    if (dp[idx] != -1)
        return dp[idx];

    // valid string found
    if (idx == n)
        return dp[idx] = 1;

    if (str[idx] == '0')
        return dp[idx] = 0;

    dp[idx] = solve(idx + 1, str, n, dp);

    // We have to put this check here and not with str[idx] == '2'
    // as we need to confirm there are 2 elements remaining in the string
    if (idx + 1 < n)
    {
        if (str[idx] == '1' || (str[idx] == '2' && str[idx + 1] <= '6'))
            dp[idx] += solve(idx + 2, str, n, dp);
    }

    return dp[idx];
}

public:
    int numDecodings(string s)
    {
        int n = s.length();
        vector<int> dp(n + 1, -1);

        solve(0, s, n, dp);
        return dp[0];
    }
};


// Bottom-up approach, O(n) time and O(n) space
class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.length();

        // dp[i] -> number of decode ways from i till n
        vector<int> dp(n + 2, 0);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; --i)
        {
            dp[i] = (s[i] == '0') ? 0 : dp[i + 1];

            if (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')
                dp[i] += dp[i + 2];
        }
        return dp[0];
    }
};


int main()
{
    fastio();
    
    return 0;
}

