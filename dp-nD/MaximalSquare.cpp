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
Brute force
------------
rows = m, cols = n, square side = k
Worst case: matrix full of '1'.

For every cell:
you may expand up to min(m,n)
every expansion checks O(k) cells

So: O(m ∗ n ∗ k^2) time complexity
where: k=min(m,n)
O(m ∗ n ∗ min(m,n)^2)
*/
class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxSide = 0;

        for (int row = 0; row < m; ++row)
        {
            for (int col = 0; col < n; ++col)
            {
                if (matrix[row][col] == '0')
                    continue;

                int currSide = 1;
                maxSide = max(maxSide, currSide);

                bool canExpand = true;

                while (canExpand &&
                       row + currSide < m &&
                       col + currSide < n)
                {
                    // check new bottom row
                    for (int j = col; j <= col + currSide; ++j)
                    {
                        if (matrix[row + currSide][j] == '0')
                        {
                            canExpand = false;
                            break;
                        }
                    }

                    // check new right column
                    for (int i = row; i < row + currSide; ++i)
                    {
                        if (matrix[i][col + currSide] == '0')
                        {
                            canExpand = false;
                            break;
                        }
                    }

                    if (canExpand)
                    {
                        ++currSide;
                        maxSide = max(maxSide, currSide);
                    }
                }
            }
        }

        return maxSide * maxSide;
    }
};


// O(mxn) time and space complexity
class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxSide = 0;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (matrix[i - 1][j - 1] == '0')
                    dp[i][j] = 0;

                else
                    dp[i][j] = 1 + min({dp[i - 1][j],
                                    dp[i][j - 1],
                                    dp[i - 1][j - 1]});

                maxSide = max(maxSide, dp[i][j]);
            }
        }

        for (const auto& x : dp)
        {
            for (const auto& y : x)
                cout << y << " ";
            cout << "\n";
        }

        return maxSide * maxSide;
    }
};


    
int main()
{
    fastio();
    
    return 0;
}
