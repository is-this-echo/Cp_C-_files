#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
// leetcode -> 76. Minimum Window Substring
 
string minWindow(string s, string p) {
    unordered_map<char,int>ms,mp;
    int cnt=0,start=0;
    int min_window_len=INT_MAX,window_len=0,min_start=0;
    
    for(auto ch : p)
        mp[ch]++;
    
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        ms[ch]++;
        
        if(mp[ch]!=0 && ms[ch]<=mp[ch]){
            cnt+=1;
        }
        
        // contracting window
        if(cnt==p.length()){
            while(mp[s[start]]==0 || ms[s[start]]>mp[s[start]]){
                ms[s[start]]--;
                start++;
            }
            window_len=i-start+1;
            
            if(window_len<min_window_len){
                min_window_len = window_len;
                min_start=start;
            }
        }
        
    }
    
    return min_window_len==INT_MAX ? "" : s.substr(min_start,min_window_len);
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    return 0;
}