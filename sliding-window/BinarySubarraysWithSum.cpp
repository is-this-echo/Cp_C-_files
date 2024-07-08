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



// This counts the number of subarrays with sum <= goal.
// If we have a non-binary array, then we can either create another array
// by applying some logic or add to the running sum accordingly without
// requiring extra space.
// Ex:  nums = [2,2,2,1,2,2,1,2,2,2], goal = 2
// A continuous subarray is called nice if there are k odd numbers on it.
// Return the number of nice sub-arrays.
// pref += (nums[i] & 1); pref -= (nums[l] & 1);
int solve(vector<int>& nums, const int& sum)
{
    if (sum < 0) return 0;

    int ans = 0;
    int l = 0, pref = 0;
    
    for (int i = 0; i < nums.size(); ++i)
    {
        pref += nums[i];
        while (pref > sum)
        {
            pref -= nums[l];
            l++;
        }
        ans += (i - l + 1);
    }
    return ans;
}

// Time complexity = O(n), space complexity = O(1)
int numSubarraysWithSum(vector<int>& nums, int goal) {

    // The idea is to find the subrrays possible with sum <= goal &sum<=goal-1,
    // then subtract the two to get the final answer.
    // Trivial sliding window approach is good for solving sum <= or >= k 
    // but not exact value like sum = k;
    return solve(nums, goal) - solve(nums, goal-1);
}
    
int main() {
    fastio();

    return 0;
}