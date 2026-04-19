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
    
 
class Solution
{
    int lowerBound(vector<int>& nums, int key)
    {
        int start = 0, end = nums.size() - 1;
        int ans  = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == key)
            {
                ans = mid;
                end = mid - 1;
            }
            else if (nums[mid] < key)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int>& nums, int key)
    {
        int start = 0, end = nums.size() - 1;
        int ans  = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == key)
            {
                ans = mid;
                start = mid + 1;
            }
            else if (nums[mid] < key)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        return {lowerBound(nums, target), upperBound(nums, target)};
    }
};

    
int main()
{
    fastio();
    
    return 0;
}