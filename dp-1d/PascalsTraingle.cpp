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
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int row = 0; row < numRows; ++row)
            ans.emplace_back(vector<int>(row + 1, 1));

        for (int row = 2; row < numRows; ++row)
            for (int col = 1; col < row; +s+col)
                ans[row][col] = ans[row - 1][col - 1] + ans[row - 1][col];
        
        return ans;
    }
};


int main() {
    fastio();
    
    return 0;
}