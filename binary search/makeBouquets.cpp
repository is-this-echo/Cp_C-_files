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
    
 
// Leetcode : 1482. Minimum Number of Days to Make m Bouquets
/* You are given an integer array bloomDay, an integer m and an integer k.
You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.
*/
class Solution {
    bool makeBuoquet(vector<int>&arr, int bouquet, int k, int days){
        int currBuoquets = 0, currFlowers = 0;

        for (int i=0; i<arr.size(); i++){
            // flower not yet bloomed, break streak
            if (arr[i] > days) {
                currFlowers = 0;
                continue;
            }
            currFlowers++;

            // buoquet condition met, increment count & reset streak
            if (currFlowers == k){
                currBuoquets++;
                currFlowers = 0;
                if (currBuoquets == bouquet)
                    return true;
            }
        }
        return false;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        using ll = long long int;
        if ((ll)bloomDay.size() < (ll)m*k)
            return -1;
        
        int low = INT_MAX;
        int high = INT_MIN;

        // define monotonic search space
        for (int x : bloomDay){
            low = min(low, x);
            high = max(high, x);
        }

        int ans = high;

        while (low <= high){
            int mid = low + (high-low)/2;

            if (makeBuoquet(bloomDay, m, k, mid)){
                ans = mid; 
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};
    
int main() {
    fastio();
    
    return 0;
}