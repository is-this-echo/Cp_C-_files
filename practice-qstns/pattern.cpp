#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define INF 2e18
#define mod 998244353
const double eps = 1e-12;


/*    
     A
    ABA
   ABCBA
  ABCDCBA
 ABCDEDCBA

*/


void solve(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=2*i-1;j++){
            cout<<j;
        }
        cout<<"\n";
    }
}


void solve2(){
    int n,x,y;
    cin>>n>>x>>y;

    cout<<((x+y)&1 ? 1 : 0)<<"\n";
}

    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    solve();
    
    return 0;
}