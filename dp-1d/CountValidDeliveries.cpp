#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
//#define mod 998244353
const double eps = 1e-12;
    

const ll mod = 1e9+7;

ll fact(int x){
    if(x==1)
        return 1;
    
    return x*fact(x-1)%mod;
}


ll countOrders(int n){
    ll ans=1,i=0;

 // will run n-1 times
    while((2*n-(2*i+1))>0){
        ans = ans * (2*n-(2*i+1)) % mod;
        i++;
    }
    
    return ans * fact(n) % mod;
}

    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin>>n;
    cout<<countOrders(n);
    
    return 0;
}