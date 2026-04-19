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
    int longestOnes(vector<int>& nums, int k)
    {
        int zeros = 0;
        int left = 0, right;
        int maxOnes = 0;

        for (right = 0; right < nums.size(); right++)
        {
            if (nums[right] == 0)
                zeros++;

            while (zeros > k)
            {
                if (nums[left] == 0)
                    zeros--;

                left++;
            }

            maxOnes = std::max(maxOnes, right - left + 1);
        }

        return maxOnes;
    }
};


int main()
{
    fastio();

    return 0;
}