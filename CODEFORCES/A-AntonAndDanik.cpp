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

    cin>>n;
    cin>>s;

    int anton=0,danik=0;

    for(auto x: s){
        if(x=='A')
            anton++;
        else
            danik++;
    }

    if(anton>danik)
        cout<<"Anton"<<"\n";
        
    else if(danik>anton)
        cout<<"Danik"<<"\n";
    
    else 
        cout<<"Friendship";

}


    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    solve();
    
    return 0;
}