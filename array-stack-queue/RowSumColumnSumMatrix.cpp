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
    
// Leetcode 1605. Find Valid Matrix Given Row and Column Sums
// Time Complexty = O(mxn), Space Complexity = O(1) not considering the output vector
vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    using ll = long long int;

    int m = rowSum.size();
    int n = colSum.size();
    vector<vector<int>> ans(m, vector<int>(n, 0));

    // matching the row sum first
    for (int row = 0; row < m; ++row)
        ans[row][0] = rowSum[i];  

    // matching the columns keeping rowSum intact
    for (int col = 0; col < n; ++col)
    {
        ll currColSum = 0;
        for (int row = 0; row < m; ++j)
            currColSum += ans[row][col];

        ll extraSum = currColSum - colSum[col];
        for (int row = 0; row < m; ++j)
        {
            int lowerNum = std::min<ll>(ans[row][col], extraSum);
            ans[row][col] -= lowerNum;

            if (i < n-1)
                ans[row][col+1] += lowerNum;

            extraSum -= lowerNum;
        }
    }
    return ans;
}


int main() {
    fastio();
    
    return 0;
}