#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 998244353
double eps = 1e-12;
    

 bool helper(string s, int i, vector<string> &wordDict, int n){   
    if(i==n)
        return true;
    
    for(string x : wordDict){
        int l = x.length();
        if(s.substr(i,l)==x){
            //cout<<"same";
            i=i+l;
            return helper(s,i,wordDict,n);
        }     
    }
        
    return false;
}
    
    
    
bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    return helper(s,0,wordDict,n);
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s = "leetcode";
    vector<string> v = {"code","leet"};

    cout<<wordBreak(s,v);
    
    return 0;
}