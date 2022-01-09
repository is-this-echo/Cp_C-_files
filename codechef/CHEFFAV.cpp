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

    string s;
    cin>>s;

    string str="";

    for(int i=0;i<n;i++){
        if(s[i]=='c' && s[i+1]=='h' && s[i+2]=='e' && s[i+3]=='f'){
            //if(str=="")
                cout<<"WA\n";
            //else if(str=="code")
               // cout<<"AC";

           ///cout<<"\n";
            return;
        }

        if(s[i]=='c' && s[i+1]=='o' && s[i+2]=='d' && s[i+3]=='e'){
            cout<<"AC"<<"\n";
            return;
        }
    }
    return;
}


    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--)
        solve();
    
    return 0;
}