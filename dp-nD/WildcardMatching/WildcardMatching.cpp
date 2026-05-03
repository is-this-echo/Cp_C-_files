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


// Space and time both are O(m x n) complexity
// dp[i][j] means dp[str 0..i-1][pat 0..j-1] matches or not?
class Solution
{
public:
    bool isMatch(string str, string pat)
    {   
        int m = str.length();
        int n = pat.length();

        // pattern in cols, string in rows
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true; // pattern and string both are empty

        // empty string, pattern only
        for (int i = 0; i < n; ++i)
        {
            if (pat[i] == '*')
                dp[0][i + 1] = dp[0][i];
            else
                dp[0][i + 1] = false;
        }

        // empty pattern, string only
        for (int i = 0; i < m; ++i)
            dp[i + 1][0] = false;

        for (int i = 1; i <=m ; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // ? matches current character in string or both chars are equal, same as ignoring these 2 chars
                if (pat[j - 1] == '?' || pat[j - 1] == str[i - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                
                // * can match: empty sequence, one or more characters
                // dp[i][j - 1] -> * matches empty string.
                // dp[i - 1][j] -> * consumes current string character,
                // we remove one char from string, but keep * available.
                else if (pat[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

                else
                    dp[i][j] = false;
            }
        }

        for (const auto& x : dp)
        {
            for (const auto& y : x)
                cout << y << "  ";
            
            cout << "\n";
        }

        return dp[m][n];
    }
};


int main()
{
    fastio();

    return 0;
}
