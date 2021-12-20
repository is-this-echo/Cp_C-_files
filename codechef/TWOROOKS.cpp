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
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    if(x1==x2 || y1==y2)
        cout<<"YES";

    else
        cout<<"NO";
    
    cout<<"\n";

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