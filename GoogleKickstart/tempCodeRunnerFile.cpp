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
        int n;
        cin>>n;

        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];

        map<int,int>mp;
        int ans=1;
        cout<<"Case #"<<tt+1<<": ";
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            cout<<max(ans,min(mp[arr[i]],i+1))<<" ";
        }
        cout<<"\n";

    }

    return 0;
}