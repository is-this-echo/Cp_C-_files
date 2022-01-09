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
    int n;
    cin>>n;

    if(n<=2){
        cout<<0<<"\n";
        return;
    }
        
    ll ans1 = 1;
    ll ans2 = pow(3,n-3)*(n-2)*8;
    ans1 = ans2+ans2/4;

    cout<<ans1<<"\n";

}


    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--)
        solve();
    
    return 0;
}