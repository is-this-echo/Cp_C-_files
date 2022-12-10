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

    // labels
    // red->0,  yellow->1

    ll rs, rh;
    cin>>rs>>rh;

    ll n,m;
    cin>>n;

    ll x,y;

    // creating a ordered map to store <dist,label>
    map<ll,bool>mp;

    // red stones
    for(ll i=0;i<n;i++){
        cin>>x>>y;

        // calculate euclidean distance from centre
        ll dist_squared = x*x + y*y;

        if(dist_squared<= pow(rs+rh,2))
            mp[dist_squared]=0;
    }

    cin>>m;

    // yellow stones
    for(ll i=0;i<m;i++){
        cin>>x>>y;

        // calculate euclidean distance from centre
        ll dist_squared = x*x + y*y;

        if(dist_squared<= pow(rs+rh,2))
            mp[dist_squared]=1;
    }

    ll ans = 0;
    bool team = mp.begin()->s;

    for(auto pair : mp){
        if(pair.s != team)
            break;
        
        ans++;
    }

    if(team==0)
        cout<<ans<<" "<<0;

    else
        cout<<0<<" "<<ans;
    
    cout<<"\n";
    


}
    
int main() {
    fastio();

    int t;
    cin>>t;

    for(int i=1;i<=t;i++){
        google(i);
        solve();
    }
    
    return 0;
}