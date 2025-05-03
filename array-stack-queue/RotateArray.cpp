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

// Solution-1, uses extra O(n) space and O(n) time
class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        int n = nums.size();
        k = k % n;

        vector<int> temp(n, 0);
        // formula = ((k+i) % n) gives new location after rotation
        for (int i = 0; i < n; ++i)
            temp[(k + i) % n] = nums[i];

        nums = temp;
    }
};

// Solution-2, in O(1) space and O(n) time
class Solution {
    void reverse(vector<int>& nums, int l, int r)
    {
        while (l < r)
        {
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;

            l++, r--;
        }
    }

public:
    void rotate(vector<int>& nums, int k)
    {
        int n = nums.size();
        k = k % n;

        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};

    
int main() {
    fastio();
    
    return 0;
}