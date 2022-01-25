#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
const double eps = 1e-12;
    
 
string kthLargestNumber(vector<string>& nums, int k) {
/* implement min-heap for kth largest number
    string size is very large which dont fit in long long, so a custom 
    comparator function is required */

    sort(nums.begin(),nums.end(),[&](string &a, string &b){
        if(a.length()==b.length())
            return a<b;
        return a.length()<b.length();
    });
    
    return nums[nums.size()-k];
}
    


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<string>arr = {"423","521","2","42"};
    cout<<kthLargestNumber(arr,2);
    
    return 0;
}