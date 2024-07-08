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


// 3116. Kth Smallest Amount With Single Denomination Combination
class Solution {
    using ll = long long;

    ll getSmallestAmount(vector<int>& coins, ll mid)
    {
        int n = coins.size();
        ll setBits = (1 << n) - 1; // to represent bitmask for all coins
        ll count = 0; // number of values <= mid;

        // TC = O(2^n)
        for (int mask = 1; mask <= setBits; mask++)
        {
            ll setBitsLCM = 1;
            // TC = O(n)
            for (int i = 0; i < n; i++)
                if (mask & (1 << i))  // if mask is set
                    setBitsLCM = lcm(setBitsLCM, coins[i]); // using std::lcm

            if (__builtin_popcount(mask) & 1)
                count += (mid / setBitsLCM);
            else
                count -= (mid / setBitsLCM);
        }
        return count;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // high is the max value possible by adding coin
        // with denomination=25 k_max times.
        ll  low = 1, high = 25*2*1e9, ans = 0;  

        // TC = O(n*2^n*logk)
        while (low <= high)
        {
            // as we are using long long, low + (high-low)/2 not required
            ll mid = (low + high) / 2;

            // mid = kth smallest value we are trying to find
            // k = mid/coins1 + mid/coins2 + .....
            // we also need to remove the common factors using
            // inclusion-exclusion principle.
            // TC = O(n*2^n)
            ll count = getSmallestAmount(coins, mid);

            if (count < k)
                low = mid + 1; 
            else
            {
                // try to get as close to k as possible
                ans = mid;
                high = mid - 1; 
            }
        }
        return ans;        
    }
};


int main() {
    fastio();

    return 0;
}