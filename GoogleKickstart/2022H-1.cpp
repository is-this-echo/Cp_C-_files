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
    ll n,L;
    cin>>L>>n;

    vector<pair<ll,char>>dist;
    for(int i=0;i<n;i++){
        ll val;
        char ch;
        cin>>val>>ch;

        dist.push_back({val,ch});
    }

    char lastpos = dist[0].s;
    ll ans = dist[0].f / L;
    ll rem = dist[0].f%L;

    for(int i=1;i<n;i++){
        ll dtrav = dist[i].f;
        char currpos = dist[i].s;

        if(lastpos==currpos){
            dtrav = rem + dtrav;
            ans += dtrav/L;
            rem = dtrav%L;
        }
        else{
            if(rem>dtrav){
                rem -= dtrav;
            }
            else{
                rem = dtrav-rem;
                lastpos = currpos;
            }
            ans += rem/L;
            rem = rem%L;
        }
    }
    cout<<ans<<"\n";
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