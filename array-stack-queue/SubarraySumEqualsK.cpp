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
    int subarraySum(vector<int>& nums, int k)
    {
        std::unordered_map<int, int> prefixFreq; // prefix sum, count
        int currSum = 0;
        int ans = 0;

        prefixFreq[0] = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            currSum += nums[i];
            ans += prefixFreq[currSum-k];

            // can we put this line above the one where answer
            // is calculate? the answer is no because if we do that
            // then we are saying we can remove the current subarray
            // to get a subarray sum of 'k' which is wrong, take example of
            // nums = [1]
            prefixFreq[currSum]++;
        }
        return ans;
    }
};

    
int main() {
    fastio();
    
    return 0;
}