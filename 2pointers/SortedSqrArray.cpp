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
    vector<int> sortedSquares(vector<int>& nums)
    {   
        int n = nums.size();
        vector<int> result(n, 0);

        int itr = n - 1;
        int left = 0, right = n - 1;

        while (left <= right)
        {
            if (abs(nums[left]) > abs(nums[right]))
            {
                result[itr] = nums[left] * nums[left];
                left++;
            }
            else
            {
                result[itr] = nums[right] * nums[right];
                right--;
            }
            itr--;
        }
        return result;
    }
};


int main()
{
    fastio();

    return 0;
}