#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
 

void solve(){
    char p1,p2;

    unordered_map<char,int>mp;
    mp['R']=2;
    mp['B']=1;
    mp['G']=0;

    cin>>p1>>p2;

    if(p1==p2)
        cout<<p1;
        
    else if(mp[p1]>mp[p2])
        cout<<p1;
    
    else
        cout<<p2;

}
    


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    solve();
    
    return 0;
}