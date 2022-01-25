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
    int rb,cb,rd,cd,m,n;
    cin>>n>>m>>rb>>cb>>rd>>cd;

    int dr=1,dc=1;
    int time=0;

    while(rb!=rd && cb!=cd){
        if(rb+dr>n || rb+dr<1)
            dr=-1*dr;

        if(cb+dc>m || cb+dc<1)
            dc = -1*dc;
        
        rb = rb+dr;
        cb = cb+dc;
        time++;

    }
    cout<<time<<"\n";
}
    


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--)
        solve();
    
    return 0;
}