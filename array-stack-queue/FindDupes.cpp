#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
 
vector<int> findDuplicates(vector<int>& arr) {
    vector<int>ans;
    
    for(int i=0;i<arr.size();i++){
        int val = abs(arr[i]);
        
        if(arr[val-1]<0)
            ans.push_back(val);
        
        else
            arr[val-1] = -1* arr[val-1]; 
    }
    return ans;
}


 

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<int>nums = {4,3,2,7,8,2,3,1,8,5,5};
    auto x = findDuplicates(nums);

    for(auto y : x)
        cout<<y<<" ";
    
    return 0;
}