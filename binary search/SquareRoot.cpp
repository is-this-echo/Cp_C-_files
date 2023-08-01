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
    

 // use binary search to find out the square root of a number

void solve(ll n, ll p){
// integer part using binary search
    ll s = 0, e = n;
    double ans;

    while(s<=e){
        ll mid = s + (e-s)/2;

        if(mid*mid==n){
            ans = mid;
            break;
        }
        else if(mid*mid<n){
            ans = mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout<<"Integer part: "<<ans<<"\n";

// decimal part using linear search, p denotes number of decimal places
    double f=0.1;

    for(ll places=1;places<=p;places++){
        while(ans*ans<=n){
            ans+=f;
        }

        ans-=f;
        f = f/10.0;
    }
    cout<<"Square root upto "<<p<<" places = "<<ans;
}

    
int main() {
    fastio();

    ll n,p;
    cin>>n>>p;

    solve(n,p);
    
    return 0;
}