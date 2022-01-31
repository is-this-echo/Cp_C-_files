
// Given 2  n dimensional vectors A & B, it is allowed to change the order of elements 
// in A & B . Shuffle the elements in A and B such that their dot product is minimum.
// Return the dot product

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


#define ll long long
#define mod 998244353
double eps = 1e-12;


ll minDotProduct(vector<int>&a, vector<int>&b){
    ll ans=0;

    int n = a.size();
    int m = b.size();
    // if two vectors of unequal dimensions are given
    if(m!=n)
        return mod;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    for(int i=0;i<n;i++)
        ans += a[i]*b[n-i-1];
    
    return ans;
}

    

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<int>A = {1,3,-5}, B={-2,4,1};

    cout<<minDotProduct(A,B); 

    return 0;
}