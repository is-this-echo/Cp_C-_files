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
public:
    int triangleNumber(vector<int>& nums)
    {
        if (nums.size() < 3)
            return 0;
        
        int ans = 0;
        std::ranges::sort(nums);

        for (int i = 2; i < nums.size(); ++i)
        {
            int left = 0, right = i -1;
            while (left < right)
            {
                if (nums[left] + nums[right] > nums[i]) 
                {   // for a triplet to form a triangle, the sum of any 2 sides
                    // should be greater than the third size
                    ans += (right - left); 
                    // consider sides i, right and all elements from left to right
                    // if left forms a sum > largest side, the elements after left
                    // will also do the same as array is sorted.
                    right--; // to take different 2nd side and also to stop while loop.
                }
                else
                {   // if left + right sides are smaller than the third side,
                    // move forward.
                    left++;
                }
            }
        }
        return ans;
    }
};

    
int main() {
    fastio();
    
    return 0;
}