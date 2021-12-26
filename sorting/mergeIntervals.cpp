
// 56. Merge Intervals

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
 
vector<vector<int>> merge(vector<vector<int>>& arr) {  
    /* sort(arr.begin(),arr.end(), [&](vector<int>&a, vector<int>&b){
        return a[0]<=b[0];
    });
    
    if(arr.size()==1)
        return arr;
    
    vector<vector<int>>ans;
    ans.push_back(arr[0]);
    
    for(int i=1;i<arr.size();i++){
        //vector<int>temp = *(ans.end()-1);
        //vector<int>temp = ans.back();
        
        if(arr[i][0]<=ans.back()[1]){
            int e = max(ans.back()[1],arr[i][1]);
            ans.back()[1]=e;
        }
        
        else ans.push_back(arr[i]);
    }
    
    return ans;
    */
      
    sort(arr.begin(),arr.end());
    
    vector<vector<int>> ans = {arr[0]};
    
    for(int i=1;i<arr.size();i++){
        if(arr[i][0]>ans.back()[1]) 
            ans.push_back(arr[i]);
        else
            ans.back()[1] = max(ans.back()[1],arr[i][1]); 
    }
    return ans;
    
}


    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    return 0;
}