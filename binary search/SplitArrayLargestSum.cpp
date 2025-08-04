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

    bool canSplit(vector<int>& nums, int sum, int k)
    {
        int subarrays = 0;
        int currSum = 0;
        // find if the sum of each subarray can be <= sum
        for (int x : nums)
        {
            if (x + currSum > sum)
            {   
                subarrays++;
                currSum = x;

                if (subarrays == k)
                    return false;
            }
            else
            {
                currSum += x;
            }
        }
        return true;
    }

public:
    int splitArray(vector<int>& nums, int k)
    {
        // similar to allocate pages to students problem using binary search
        int start = *std::max_element(nums.begin(), nums.end());
        int end = std::accumulate(nums.begin(), nums.end(), 0);

        int ans = start;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (canSplit(nums, mid, k))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }
};

    
int main() {
    fastio();
    
    return 0;
}