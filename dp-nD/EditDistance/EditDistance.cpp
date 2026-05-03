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
O(m * n) time and space complexity.
If word1 & word2 char match then we check for prev chars in both - same as current char not existing.
If they are different, then we do any of the below operations and take the min of these + 1.
dp[i - 1][j - 1] -> dp[i][j]  // replace in word1, make the curr  char same as word2
dp[i][j - 1] -> dp[i][j]  // insert in word1, i remains same but j increased as we inserted word2[j-1] in word1
dp[i - 1][j] -> dp[i][j]  // delete in word1, curr char is deleted in word2, so increase i

dp(i,j) -> Min operations required to convert word1[0..i] to word2[0..j]
*/
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        // word1 -> word2
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 0; // both words are empty, no operation required

        // fill first row, if word2 is empty
        for (int i = 1; i <= n; ++i)
            dp[0][i] = i;

        // fill first col, if word1 is empty
        for (int i = 1; i <= m; ++i)
            dp[i][0] = i;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];

                else
                    dp[i][j] = 1 + min({dp[i - 1][j - 1], // replace in word1
                                        dp[i][j - 1], // insert in word1
                                        dp[i - 1][j]}); // delete in word1
            }
        }
        return dp[m][n];
    }
};


int main()
{
    fastio();
    
    return 0;
}

