#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
 
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    int n = intervals.size(),flag=0;
    
    if(n==0){
        ans.push_back(newInterval);
        return ans;
    }
        
    for(int i=0;i<n;i++){
        if(newInterval[0]<intervals[i][0]){
            intervals.insert(intervals.begin()+i, newInterval);
            flag=1; break;
        }
    } 
    
    if(flag==0)
        intervals.push_back(newInterval);
    
    // problem gets converted to merge-intervals 
    // also note that size of intervals increased by 1
    ans.push_back(intervals[0]);
    
    for(int i=1;i<n+1;i++){
        if(intervals[i][0]<=ans.back()[1])
            ans.back()[1] = max(ans.back()[1],intervals[i][1]);
        
        else
            ans.push_back(intervals[i]);
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<vector<int>> arr = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> trr = {4,8};
    auto ans = insert(arr, trr);

    for(auto x : ans){
        for(auto y : x)
            cout<<y<<" ";
    }
    
    return 0;

}