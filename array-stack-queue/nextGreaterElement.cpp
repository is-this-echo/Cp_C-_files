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


// By doubling the size of the array we can use a O(n^2) solution as well
// without a stack but using monotonic stack helps it make O(n) solution
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> nums2{nums};
        for (int i = 0; i < n; ++i)
            nums2.emplace_back(nums[i]);

        stack<pair<int,int>> stk; // num, idx
        vector<int> ans(n, -1);

        for (int i = 0; i < nums2.size(); ++i)
        {
            while (!stk.empty() && stk.top().first < nums2[i])
            {
                ans[stk.top().second] = nums2[i];
                stk.pop();
            }
            
            if (i < n)
                stk.push({nums2[i], i});
        }

        return ans;
    }
};


// Here, we don't use an extended duplicate nums array, instead
// we take a virtual array of size 2n and modulo index i with n
// to get the next greater element in a circular fashion
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int n = nums.size();
        stack<pair<int,int>> stk; // num, idx
        vector<int> ans(n, -1);

        for (int i = 0; i < 2 * n; ++i)
        {
            while (!stk.empty() && stk.top().first < nums[i % n])
            {
                ans[stk.top().second] = nums[i % n];
                stk.pop();
            }

            if (i < n)
                stk.push({nums[i], i});
        }
        return ans;
    }
};


int main() {
    fastio();
    
    return 0;
}