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
    


void solve(int n){

    if(n==1){
        cout<<1<<"\n";
        cout<<1;

        return;
    }

    if(n==2){
        cout<<1<<"\n";
        cout<<1<<" "<<1;
        
        return;
    }

    vector<bool> arr(100005,1);
    arr[0]=0, arr[1]=0;

    for(int i=2;i*i<=(n+1);i++){
        if(arr[i]){
            for(ll j = 1LL*i*i; j<=n+1; j+=i){
                arr[j] = 0;
            }
        }
    }

    cout<<2<<"\n";

    for(int i=2;i<=n+1;i++){
        if(arr[i])
            cout<<1;
        else
            cout<<2;

        cout<<" ";
    }

}
    
    
int main() {
    fastio();

    int n;
    cin>>n;

    solve(n);
    
    return 0;
}