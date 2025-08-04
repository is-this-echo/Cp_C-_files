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
    bool canFinish(vector<int>& piles, int speed, int hrs)
    {
        if (speed == 0)
            return false;

        int currHrs = 0;
        for (int bananas : piles)
        {
            currHrs += (bananas % speed == 0 ? bananas / speed : bananas / speed + 1);
        }

        return currHrs <= hrs;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int start = 0;
        int end = *std::max_element(piles.begin(), piles.end());

        int ans = end;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            
            if (canFinish(piles, mid, h))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
    return ans;
    }
};

    
int main() {
    fastio();
    
    return 0;
}