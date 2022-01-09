#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    

 // Leetcode 739. Daily Temperatures
 // Monotonic stack, here decreasing order

vector<int> dailyTemperatures(vector<int>& temp) {
    int n= temp.size();
    stack<pair<int,int>>stk;
    vector<int>ans(n,0);
    
    for(int i=0;i<n;i++){
        while(!stk.empty() && stk.top().first<temp[i]){
            ans[stk.top().second] = i-stk.top().second;
            stk.pop();
        }
        stk.push({temp[i],i});
    }
    return ans;
}


    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<int> arr = {73,74,75,71,69,72,76,73};
    auto x = dailyTemperatures(arr);

    for(auto i : x)
        cout<<i<<"  ";

    
    return 0;
}