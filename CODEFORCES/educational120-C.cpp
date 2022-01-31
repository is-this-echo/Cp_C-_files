#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
const double eps = 1e-12;
    
 

void solve(){
    ll n,k;
    cin>>n>>k;

    vector<ll>arr(n);
    ll total_sum=0;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        total_sum+= arr[i];
    }

    if(total_sum<=k){
        cout<<0<<"\n";
        return;
    }

    sort(arr.begin(),arr.end());

    ll diff = total_sum-k;
    ll ans = total_sum-k;
    total_sum=0;

    for(ll i=n;i>1;i--){
        total_sum += arr[i];
        ll x;

        if(diff-total_sum+arr[0]*(n-i+1)<=0) 
            x=0;
        else
            x = max((ll)ceil((diff-total_sum + arr[0]*(n-i+1))/(n-i+2)), 0LL);

        ans = min(ans, x + n - i + 1);
    }
        
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