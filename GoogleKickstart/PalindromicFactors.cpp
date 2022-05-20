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



bool isPalindrome(ll a){
    string s = to_string(a);
    int n = s.length();

    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1])
            return false;
    }
    return true;
}
 

void solve(){
    ll a;
    cin>>a;

    int cnt=0;

    for(ll i=1;i*i<=a;i++){
        if(a%i==0){
            cnt += isPalindrome(i);

            if(i*i!=a)
                cnt += isPalindrome(a/i);
        }
    }

    cout<<cnt<<"\n";
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