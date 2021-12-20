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

    int k_count=0;
    n=n-1;

    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            k_count++;

            if(i*i !=n)
                k_count++;
        }
    }
    cout<<k_count<<"\n";
}
    



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        solve();
    }
    
    return 0;
}