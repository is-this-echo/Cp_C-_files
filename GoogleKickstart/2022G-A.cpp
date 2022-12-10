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
    int nop,days,id;
    cin>>nop>>days>>id;

    // nop - > rows, days -> cols

    vector<int>maxSteps(days,0);
    vector<int>idSteps(days,0);
    int steps=0;

    for(int i=1;i<=nop;i++){
        for(int j=1;j<=days;j++){
            cin>>steps;
            maxSteps[j-1] = max(maxSteps[j-1],steps);

            if(i==id)
                idSteps[j-1]=steps;
        }
    }

    ll ans=0;

    for(int i=0;i<days;i++){
        ans += abs(idSteps[i]-maxSteps[i]);
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