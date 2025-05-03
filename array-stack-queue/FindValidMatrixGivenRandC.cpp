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
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        using ll = long long int;

        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        // matching the row sum first
        for (int i = 0; i < m; ++i)
            ans[i][0] = rowSum[i];  

        // Matching the columns keeping rowSum intact.
        // For every column, find the extra sum across all rows, then for
        // every row find the lower number = min(extra, row[j]) and decrease
        // row value by the lower amount and increment it to the next column.
        for (int i = 0; i < n - 1; ++i) // upto n-2 as the last column always is correct
        {
            ll currColSum = 0;
            for (int j = 0; j < m; ++j)
                currColSum += ans[j][i];

            ll extraSum = currColSum - colSum[i];
            for (int j = 0; j < m; ++j)
            {
                int lowerNum = std::min<ll>(ans[j][i], extraSum);
                ans[j][i] -= lowerNum;

                // can't do for i = n-1, remove this check if i < n-1 in the outer loop
                if (i < n-1)
                    ans[j][i+1] += lowerNum;

                extraSum -= lowerNum;
                if (extraSum == 0) // if no extra sum, then no need to check remaining rows
                    break;
            }
        }
        return ans;
    }
};

    
int main() {
    fastio();
    
    return 0;
}