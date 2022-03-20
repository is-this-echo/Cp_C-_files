#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    


int solve(){
    string i,p;
    cin>>i>>p;

    int ans = -1;
    int pl = p.length(), il = i.length();

    if(pl<il){
        return -1;
    }
    
    else{
        int j=0,k=0;
        while(j<il && k<pl){
            if(i[j]==p[k]){
                j++;
            }
            k++;
        }
        if(j==il){
            ans = pl-il;
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int ts;

    cin>>ts;

    for(int tt=0;tt<ts;tt++){
        int ans = solve();
        
        if(ans==-1)
            cout<<"Case "<<"#"<<tt+1<<": "<<"IMPOSSIBLE"<<"\n";

        else
            cout<<"Case "<<"#"<<tt+1<<": "<<ans<<"\n";
    }
            
    
    return 0;
}