#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 998244353
double eps = 1e-12;
    



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    char first,second,third;
    char x,y;

    int t;
    cin>>t;

    while(t--){
        cin>>first>>second>>third;
        cin>>x>>y;

        map<char,int>mp;
        mp[first]=1;
        mp[second] = 2;
        mp[third] = 3;

        if(mp[x]>mp[y])
            cout<<y<<"\n";
        else 
            cout<<x<<"\n";

    }
    
    return 0;
}