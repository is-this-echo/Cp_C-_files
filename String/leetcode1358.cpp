#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
 
int numberOfSubstrings(string str) {
    int cnt=0,l=0,r;
    int n=str.size();
    unordered_map<char,int>mp;
    
    for(r=0;r<n;r++){
        mp[str[r]]++;
        
        while(mp['a'] && mp['b'] && mp['c']){
            cnt += n-r;
            mp[str[l]]--; l++;

        }
    }
    
    return cnt;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    string str = "abcabc";
    cout<<numberOfSubstrings(str);
    
    return 0;
}