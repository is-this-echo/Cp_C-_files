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


    if(n==1){
        cout<<1<<"\n";
        cout<<1<<" "<<1<<"\n";
    }

    else if(n==2){
        cout<<2<<"\n";
        cout<<3<<" "<<1<<"\n";
        cout<<4<<" "<<1<<"\n";
    }

    else if(n==4){
        cout<<1<<"\n";
        cout<<2<<" "<<4<<"\n";
    }

    else{
        cout<<2<<"\n";
        cout<<n-2<<" "<<1<<"\n";
        cout<<2<<" "<<n-1<<"\n";
    }

}


    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--)
        solve();
    
    return 0;
}