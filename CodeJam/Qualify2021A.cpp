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

    int ts;
    cin>>ts;

    for(int tt=0;tt<ts;tt++){
        int x,y;
        cin>>x>>y;

        string s,str="";
        cin>>s;

        ll ans=0;
        for(auto ch : s){
            if(ch!='?')
                str+=ch;
        }

        for(int i=0;i+1<str.length();i++){
            if(str[i]=='C' && str[i+1]=='J')
                ans+=x;
            if(str[i]=='J' && str[i+1]=='C') 
                ans+=y;
        }

        cout<<"Case #"<<tt+1<<": "<<ans<<"\n";
    }
    
    return 0;
}