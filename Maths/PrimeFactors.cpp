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
    
 
 
using ii = pair<ll,ll>;

vector<ii>Factors(ll n){
    vector<ii>ans;

    for(ll i=2; i*i<=n; i++){
        if(n%i==0){
            int cnt=0;

            while(n%i==0){
                cnt++;
                n/=i;
            }
            ans.push_back({i,cnt});
        }
    }

    if(n>1)
        ans.push_back({n,1});

    return ans;
}
    

int main() {
    fastio();

    ll n;
    cin>>n;

    vector<ii>ans = Factors(n);

    for(auto pExp : ans){
        cout<<pExp.f<<" : "<<pExp.s<<" times"<<"\n";
    }
    
    return 0;
}