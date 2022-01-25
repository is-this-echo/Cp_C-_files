#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
const double eps = 1e-12;
    
 
// Given an array of numbers from 1 to n with 2 numbers misssing. Find the 2 missing numbers.
// Input-> [1,2,5,6]
// Output-> [3,4]
// ----1,2,3,4,5,6----


void solve(vector<int>&nums){
    int n=nums.size()+2;
    int arrSum=0,pivot;
    int totalSum = n*(n+1)/2;
    
    for(int i : nums)
        arrSum+=i;
    
    pivot = (totalSum-arrSum)>>1;

    int totalXorLeft=0,totalXorRight=0,arrXorLeft=0,arrXorRight=0;
    for(int i=1;i<=pivot;i++)
        totalXorLeft^=i;
    
    for(int i=pivot+1;i<=n;i++)
        totalXorRight^=i;
    
    for(auto i : nums){
        if(i<=pivot)
            arrXorLeft^=i;
        else 
            arrXorRight^=i;
    }

    cout<<"The first missing no. is: "<<(totalXorLeft ^ arrXorLeft)<<"\n";
    cout<<"The 2nd one is: "<<(totalXorRight ^ arrXorRight); 
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector<int>nums{1,2,5,6};

    solve(nums);
    
    return 0;
}