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
    int n,q;
    cin >> n >> q;

    vector<int>num(n);
    for(int i=0; i<n; i++){
        cin >> num[i];
    }

    vector<ll>pref(n);
    for(int i=0; i<n; i++){
        if(i==0)
            pref[i] = num[i];
        else
            pref[i] = pref[i-1] + num[i];
    }
    
    int a,b;
    while(q--){
        cin >> a >> b;
        a--; b--;

        if(a==0)
            cout << pref[b];
        else
            cout << (pref[b] - pref[a-1]);

        cout << endl;
    }
}
    

int main() {
    fastio();

    solve();
    
    return 0;
}