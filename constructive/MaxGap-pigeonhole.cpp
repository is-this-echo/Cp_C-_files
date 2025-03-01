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
    

// Leetcode 164. Maximum Gap
int maximumGap(vector<int>& nums)
{
    int maxGap = 0;
    int n = nums.size();

    if ( n < 2)
        return maxGap;

    // const auto [minItr, maxItr] = std::minmax_element(nums.begin(), nums.end());
    int minElem = INT_MAX, maxElem = INT_MIN;
    for (const auto x : nums)
    {
        minElem = min(minElem, x);
        maxElem = max(maxElem, x);
    }
    
    vector<pair<int,int>> buckets(n-1);
    std::for_each(buckets.begin(), buckets.end(), [](auto& pp){
        pp.first = INT_MAX; // min elem
        pp.second = INT_MIN; // max elem
    });

    int bucketSize = std::ceil((double)(maxElem - minElem)/(n-1));
    // std::cout << bucketSize << std::endl;
    for (int i = 0; i < n; ++i)
    {   const int& x = nums[i];
        if (x == minElem || x == maxElem)
            continue;
        
        int elemBktIdx = (x - minElem)/bucketSize;
        buckets[elemBktIdx].first = min(buckets[elemBktIdx].first, x);
        buckets[elemBktIdx].second = max(buckets[elemBktIdx].second, x);
    }

    // min of right bucket - max of left bucket
    int leftMax = minElem;
    for (int i = 0; i < n - 1; ++i)
    {
        if (buckets[i].second == INT_MIN)
            continue;
        
        maxGap = max(maxGap, buckets[i].first - leftMax);
        leftMax = buckets[i].second;
    }
    // std::cout << leftMax << std::endl;
    maxGap = max(maxGap, maxElem - leftMax);
    return maxGap;
}

int main() {
    fastio();

    vector<int> nums{100, 3, 2, 1};
    std::cout << maximumGap(nums);
    
    return 0;
}