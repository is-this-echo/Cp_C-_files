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

    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    // odd positions
    int first = arr[1]%2;

    for(int i=3;i<=n;i+=2){
        if(arr[i]%2 != first){
            cout<<"NO"<<"\n";
            return;
        }
    }


    // even positions
    first = arr[2]%2;

    for(int i=4;i<=n;i+=2){
        if(arr[i]%2 != first){
            cout<<"NO"<<"\n";
            return;
        }
    }

    cout<<"YES"<<"\n";

}
    

int main() {
    fastio();

    int t;
    cin>>t;

    while(t--)
        solve();
    
    return 0;
}