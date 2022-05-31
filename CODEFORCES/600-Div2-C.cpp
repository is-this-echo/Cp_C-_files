/* Debjyoti Ghosh*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define INF 2e18
#define PI 3.1415926535897932384626
#define mod 998244353
#define f first
#define s second 

double eps = 1e-12;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void google(int t) {cout << "Case #" << t << ": ";}
    
 

void solve(){
    ll n,m;
    cin>>n>>m;

    vector<ll>arr(n+1);
    for(int i=1;i<=n;i++)
        cin>>arr[i];

    sort(arr.begin(),arr.end());

    vector<ll>pref(n+1);

    for(int i=1;i<=n;i++){
        if(i==1)
            pref[i] = arr[i];
        
        else
            pref[i] = pref[i-1] + arr[i];
    }

    for(int k=1;k<=n;k++){
        if(k<=m)
            cout<<pref[k]<<" ";
        
        else{
            int day = (k%m==0) ? k/m : k/m + 1;
            ll ans=0;

            for(int i=1;i<=day;i++){
                if(k-i*m>=0)
                    ans += (pref[k-(i-1)*m] - pref[k-i*m])*1LL*i;
                else
                    ans += pref[k-(i-1)*m]*1LL*i;
             }
             cout<<ans<<" ";
        }
    }

}

    
int main() {
    fastio();

    solve();
    
    return 0;
}