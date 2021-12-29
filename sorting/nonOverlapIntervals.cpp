// 435. Non-overlapping Intervals

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
 

int eraseOverlapIntervals(vector<vector<int>>& arr) {
    int ans=0;
    
    sort(arr.begin(),arr.end(), [&](const vector<int>&a, const vector<int>&b){
        return a[0]<b[0];
    });
    
    int currEnd = arr[0][1]; 
    
    for(int i=1;i<arr.size();i++){
        int start = arr[i][0], end = arr[i][1];
        if(start<currEnd){
            ans++;
            currEnd = min(end,currEnd);
        }    
        
        else    
            currEnd = arr[i][1];
    }
    
    return ans;
} 



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    return 0;
}