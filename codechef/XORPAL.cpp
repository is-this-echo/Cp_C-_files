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
    string s;
    cin>>n>>s;

    int n_one=0,n_zero=0;

    for(auto i : s){
        if(i=='1')
            n_one++;
        else
            n_zero++;
    }

    // if string size is odd
    if(n&1){
        cout<<"YES"<<"\n";
        return;
    }

    // if string size is even
    if((n_one&1) || (n_zero&1)){
        if(n_one == n_zero)
            cout<<"YES"<<"\n";

        else
            cout<<"NO"<<"\n";

        return;
    }

    else
        cout<<"YES"<<"\n";

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