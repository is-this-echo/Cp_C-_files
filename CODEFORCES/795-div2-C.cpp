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
    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    int fpos=-1, lpos=-1, ones=0, flagl=n-1, flagf=1;
    ll sum=0; 

    for(int i=n-1;i>=0;i--){
        if(s[i]=='1'){
            lpos=n-1-i;
            break;
        }
    }
 
    if(k>=lpos){
        k-=lpos;
        sum += 1;
        flagl=n-2;
        swap(s[n-1-lpos],s[n-1]);
    }

    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            fpos=i;
            break;
        }
    }

    if(k>=fpos && fpos!=n-1-lpos){
        sum += 10;
        flagf=n-1;
        swap(s[fpos],s[0]);
    }


    for(int i=1;i<n-1;i++){
        if(s[i]=='1')
            ones++;
    }

    sum += 11*ones;
    cout<<sum<<" "<<s<<"\n";

}
    

int main() {
    fastio();

    int t;
    cin>>t;

    while(t--)
        solve();
    
    return 0;
}