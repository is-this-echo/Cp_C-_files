#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
 /* 448. Find All Numbers Disappeared in an Array
 Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all  the integers in the range [1, n] that do not appear in nums
*/


vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int>ans;
    int val,n = nums.size();
    
    for(int i=0;i<n;i++){
        val=abs(nums[i]);
        
        if(nums[val-1]>0)
            nums[val-1] = -1 * nums[val-1];
    }

    for(int i=0;i<n;i++){
        if(nums[i]>0)
            ans.push_back(i+1);
    }
    return ans;
}
    


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    return 0;
}