/* Debjyoti Ghosh*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void google(int t) {cout << "Case #" << t << ": ";}
    
 

void solve(){
    string n;
    cin>>n;

    ll sum = 0;
    ll len = n.length();
    for(int i=0;i<len;i++)
        sum += (n[i]-'0');

    ll digit = 9 - (sum%9);
    int k=len;
    digit = (digit==9) ? 0 : digit;

    if(digit==0){
        cout<<n[0]<<"0"<<n.substr(1)<<"\n";
        return;
    }

    else{
        for(int i=0;i<len;i++){
            if((n[i]-'0')>digit){
                k=i;
                break;
            }
        }

        cout<<n.substr(0,k)<<digit<<n.substr(k)<<"\n";
    }

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