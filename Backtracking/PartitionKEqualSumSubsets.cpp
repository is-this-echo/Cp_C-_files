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
    bool partition(int idx, int currSum, int partitionsLeft, int targetSum,
                                vector<int>& nums, vector<bool>& visited)
    {
        if (partitionsLeft == 0)
            return true;

        if (currSum == targetSum)
            return partition(0, 0, partitionsLeft - 1, targetSum, nums, visited);

        for (int i = idx; i < nums.size(); ++i)
        {
            if (visited[i] || currSum + nums[i] > targetSum)
                continue;
            
            if (i > 0 && !visited[i-1] && nums[i] == nums[i-1])
                continue;
            
            visited[i] = true;

            if (partition(i + 1, currSum + nums[i], partitionsLeft,
                                                targetSum, nums, visited))
                return true;

            visited[i] = false;
        }
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum / k;

        if (totalSum % k != 0)
            return false;

        sort(nums.begin(), nums.end(), greater<int>());
        vector<bool> visited(nums.size(), false);
        return partition(0, 0, k, target, nums, visited);
    }
};

  
int main() {
    fastio();
    
    return 0;
}