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


// O(logn) TC
// Solution 1 : if mid is less than mid + 1, next potential peak is mid + 1
// else the current potential peak is the mid itself. At the end, return start index to get peak.
class Solution
{
public:
    int findPeakElement(vector<int>& nums)
    {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] < nums[mid + 1])
            {
                start = mid + 1; // current peak
            }
            else
            {
                end = mid; // next potential peak
            }
        }

        return start;
    }
};



int main()
{
    fastio();
    
    return 0;
}