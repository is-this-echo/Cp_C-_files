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
    int n;
    cin>>n;

    if(n>=1900)
        cout<<"Division 1";
    else if(n>=1600 && n<=1899)
        cout<<"Division 2";
    else if(n>=1400 && n<=1599)
        cout<<"Division 3";

    else
        cout<<"Division 4";

    cout<<"\n";
}

    
int main() {
    fastio();

    int t;
    cin>>t;

    while(t--)
        solve();
    
    return 0;
}