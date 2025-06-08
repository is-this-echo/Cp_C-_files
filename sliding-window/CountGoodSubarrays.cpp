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
    ll countGood(vector<int>& nums, int k) {
        ll l = 0  ;
        ll n = nums.size();
        unordered_map<int,int>mp;
        ll currPairs = 0, ans = 0;

        for(int i=0; i<n; i++){
            // expanding window right
            // on first time, any number has 0 freq, so pairs are incremented by 0;  
            currPairs += mp[nums[i]];
            mp[nums[i]]++;

            while(currPairs>=k){
                // start contracting window from left
                // if a subarray is good, all subarrays containing that subarray is good as well
                // also, during contraction the pairs count fall by mp[nums[last]]-1 .
                ans += (n-i);
                currPairs -= (mp[nums[l]]-1);
                mp[nums[l]]--;
                l++;
            }
        }
        return ans;
    }
};  


int main() {
    fastio();

    Solution st;
    vector<int> ax = {3,1,4,3,2,2,4};
    int k=2;

    cout<< st.countGood(ax,k);

    return 0;
}