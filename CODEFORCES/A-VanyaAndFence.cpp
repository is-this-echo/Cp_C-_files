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
    int n,h;
    cin>>n>>h;

    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    int minWidth=0;

    for(int i=0;i<n;i++){
        if(a[i]>h)
            minWidth+=2;
        else
            minWidth+=1;
    }

    cout<<minWidth;
}


    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    
    return 0;
}