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
        int trap(vector<int>& height) {
            // O(n) time and space complexity
            // using (min(leftmax,rightmax) - height[i]) for each cell > 0
            int n = height.size();
            vector<int>leftmax(n);
            vector<int>rightmax(n);

            int maxTillNow = 0;
            for(int i=0;i<n;i++)
            {
                maxTillNow = max(maxTillNow, height[i]);
                leftmax[i]= maxTillNow;
            }

            maxTillNow = 0;
            for(int i=n-1;i>=0;i--)
            {
                maxTillNow = max(maxTillNow, height[i]);
                rightmax[i] = maxTillNow;
            }

            int ans = 0;
            for(int i=0;i<n;i++)
            {
                int temp = min(leftmax[i],rightmax[i])-height[i];
                ans += temp;
            }
            return ans;
        }
    };


int main() {
    fastio();

    return 0;
}