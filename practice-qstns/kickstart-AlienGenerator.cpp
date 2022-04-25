#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
 
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll g,n,t;
    cin>>n;
    t=n;
    
    while(n--){
        ll ans=0;
        cin>>g;
        g*=2;

        auto divisor = [&](ll x){
            ll temp  = g/x;
            temp-=1;
            temp-=x;
            
            if(temp>=0 && temp%2==0)
                ans++;
    
        };
        
        for(ll i=1;i*i<=g;i++){
            if(g%i==0)
                divisor(i);
                
            if(i*i!=g)
                divisor(g/i);
        }
        
        cout<<"Case #"<<t-n<<": "<<ans<<"\n";
    }

    return 0;
}