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



// O(nlogn) using efficient sorting algos
// O(klogn) using max-heap with pair<frequency,value> , key = freq
// O(n) using vector<pair<int,vector<int>>> to store freq with elements

vector<int> topKFrequent(vector<int>& nums, int k) {
    int n = nums.size();
    
    vector<int>ans;
    vector<vector<int>>fq(n+1);
    unordered_map<int,int>mp;
    
    for(int x : nums){
        mp[x]++;
    }
    
    for(auto mPair : mp){
        fq[mPair.s].push_back(mPair.f);
    }
    
    for(int i=n;i>=0;i--){
        if(fq[i].size()!=0){
            for(auto p : fq[i]){
                ans.push_back(p);
            }
        }

        if(ans.size()==k)
            return ans;
    }
    
    return ans;
}
    

int main() {
    fastio();

    // your code goes here
    vector<int>nums{1,1,1,2,2,3};
    int k=2;

    vector<int>ans = topKFrequent(nums,k);

    return 0;
}