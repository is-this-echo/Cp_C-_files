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
💡 Maximum Depth of Recursion:
If the smallest number is s, then the max depth of recursion is T / s (since you're subtracting at least s each time).

💡 Branching Factor:
At each step, you have n choices (since you iterate from index to n-1), so each level could spawn up to n calls.

Time complexity : O(n*pow(T/s))

This is exponential in nature. Why?
Because we can make up to T/s recursive calls in the worst case (i.e., keep subtracting the smallest number),
and at each step, we try up to n candidates.
Note: In practice, this gets pruned early due to the if (tar < 0) base case and reuse of index, so actual runtime is much better than the upper bound.

Space complexity : O(T/s+R⋅L)

A recursive stack of maximum depth T/s
A vector v to store the current path — at most T/s elements long
The result vector res stores all valid combinations O (R.L)
*/
class Solution
{
public:
    void src(vector<int> cand, int tar, vector<vector<int>>& res,
                vector<int>& v, int index)
    {
        if (tar < 0) return;

        if (tar == 0)
        {
            res.push_back(v);
            return;
        }

        for (int i = index; i < cand.size(); i++)
        {
            v.push_back(cand[i]);
            src(cand, tar-cand[i], res, v, i);
            v.pop_back();
        }       
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> v;

        src(candidates, target, res, v, 0);
        return res;
    }
};


int main()
{
    fastio();
    
    return 0;
}