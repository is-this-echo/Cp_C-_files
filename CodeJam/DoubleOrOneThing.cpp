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
#define f first
#define s second 

double eps = 1e-12;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void google(int t) {cout << "Case #" << t << ": ";}
    
 

void solve(){
    string s,ans;
    cin>>s;

    int n = s.length();

    if(s[0]<s[1]){
        ans += (s[0]);
        ans += (s[0]);
    }
    else
        ans += s[0];
        

    for(int i=1;i<n-1;i++){
        if(s[i-1]>s[i] && s[i]<=s[i+1]){
            ans += s[i];
            ans += s[i];
        }
        else
            ans += s[i];
    }

    if(s[n-1]<s[n-2]){
        ans += s[n-1];
        ans += s[n-1];
    }
    
    else
        ans += s[n-1];
    
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