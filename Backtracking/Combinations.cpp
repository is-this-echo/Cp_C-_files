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


// 77. Combinations
// TimeComplexity = O(n^k), SpaceComplexity = O(1)
void rec(vector<vector<int>>& ans, vector<int>& temp, int n, int k, int i)
{
    if (temp.size() == k){
        ans.emplace_back(temp);
        return;
    }

    for (int idx = i; idx <= n; ++idx)
    {   
        temp.emplace_back(idx);
        rec(ans, temp, n, k, idx + 1);
        temp.pop_back();
    }
}


vector<vector<int>> combine(int n, int k) 
{ 
    vector<vector<int>> ans;
    vector<int> temp;

    rec(ans, temp, n, k, 1);
    return ans;
} 


int main() {
    fastio();

    return 0;
}