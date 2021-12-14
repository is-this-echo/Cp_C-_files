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
    int arr[5][5];
    int x,y,val;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>val;
            arr[i][j]=val;

            if(val==1)
                x=i,y=j;
        }
    }
    
    cout<<abs(2-x)+abs(2-y)<<"\n";  
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    solve();
    
    return 0;
}