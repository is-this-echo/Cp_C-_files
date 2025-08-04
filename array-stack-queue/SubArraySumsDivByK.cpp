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
    int subarraysDivByK(vector<int>& nums, int k)
    {
        /*
            sum % k = 0, and
            (sum - prefix) % k = 0 => (pref[i] - pref[j]) %k

            = ((pref[i]%k - pref[j]%k) + k)%k, adding k inside
            to cater for negative numbers, the difference inside
            can have a min. value of -(k-1).

            If two prefix sums have the same remainder when divided by 𝐾,
            the subarray between these two prefix sums is divisible by 𝐾.
            4 5 0 -2 -3, rem = 4
            4 5 0, rem = 4
            so, [-2, -3] is divisible by k.
            Keep track of reminders of prefix sum and their frequency.
        */
        int n = nums.size();
        
        // {prefix sum remainder, count}, max size of map can be 0 to k -1
        std::unordered_map<int, int> prefRem;
        int sum = 0;
        int ans = 0;

        prefRem[0] = 1;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];

            int remainder = sum < 0 ? (sum % k + k) : sum % k;
            ans += prefRem[remainder % k];
            prefRem[remainder % k]++;
        }

        return ans;
    }
};

    
int main() {
    fastio();
    
    return 0;
}