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

    vector<int>p(n);
    for(int i=0;i<n;i++)
        cin>>p[i];
    
    string s;
    cin>>s;

    vector<int>dec,inc;
    unordered_map<int,int>mp;

    for(int i=0;i<n;i++){
        if(s[i]=='0')
            dec.push_back(p[i]);
        
        else 
            inc.push_back(p[i]);
    }

    sort(dec.begin(),dec.end());
    sort(inc.begin(),inc.end());

    for(int i=0;i<dec.size();i++)
        mp[dec[i]] = i+1;

    for(int i=0;i<inc.size();i++)
        mp[inc[i]] = (dec.size()+1+i);
    
    for(int i=0;i<n;i++)
        cout<<mp[p[i]]<<" ";

    cout<<"\n";

}


    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--)
        solve();
    
    return 0;
}