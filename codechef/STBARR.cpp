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
    vector<int>arr(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];

    int maxidx=0,flag=0;
    int elem =arr[0];


    for(int i=1;i<n;i++){
        if(elem!=arr[i]){
            flag=1;
            break;
        }
    }

    if(flag==0){
        cout<<0<<"\n";
        return;
    }

    
    for(int i=1;i<n;i++){
        if(arr[i]>=elem){
            elem=arr[i];
            maxidx=i;
        }
    }

    if(maxidx!=n-1)
        cout<<2<<"\n";
    else
        cout<<1<<"\n";

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