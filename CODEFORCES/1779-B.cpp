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
    int n;
    cin>>n;

    if(n%2==0){
        cout<<"YES \n";
        int x=3;
        for(int i=1;i<=n;i++){
            cout<<x* (-1)<<" ";
            x *= -1;
        }
        cout<<"\n";
        return;
    }
    else if(n==3){
        cout<<"NO \n";
        return;
    }
    else{
        cout<<"YES \n";
        int t = n/2;
        int x = -1*t, y = t-1;

        for(int i=1;i<=n;i++){
            if(i%2==0){
                cout<<x<<" ";
            }
            else{
                cout<<y<<" ";
            }
        }
        cout<<"\n";
        return;
    }
}
    

int main() {
    fastio();

    int t;
    cin>>t;

    while(t--)
        solve();

    return 0;
}