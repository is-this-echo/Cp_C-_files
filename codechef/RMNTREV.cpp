#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
 
// brute force, O(nk) time complexity
void solve2(){
    int n,k;
    cin>>n>>k;

    string s,ans,str;
    cin>>s;

    for(int i=k;i>0;i--){
        str = s.substr(i);
        ans = s.substr(0,i);
        reverse(ans.begin(),ans.end());
        s = ans+str;
    }
    cout<<s<<"\n";
}
    

void solve(){
    int n,k;
    cin>>n>>k;

    string s,ans="";
    cin>>s;

    int i=0,j=k-1;
    while(i<j){
        ans+=s[i];
        ans+=s[j];

        i++,j--;
    }

    if(i==j)
        ans+=s[i];

    reverse(ans.begin(),ans.end());
    ans+= s.substr(k);

    cout<<ans<<"\n";

}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--)
        solve();
    
    return 0;
}