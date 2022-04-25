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

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int>pref_right(n);
    vector<int>pref_left(n);

    pref_left[0]=arr[0];
    pref_right[n-1]=arr[n-1];

    for(int i=1;i<n;i++){
        pref_left[i] = pref_left[i-1] + arr[i];
        pref_right[n-i-1] = pref_right[n-i] + arr[n-i-1];
    }

    int ans=0;

    for(int i=n-1;i>=0;i--){
        int x = pref_right[i];

        int s=0, e=n-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(pref_left[mid]==x){
                if(i>mid)
                    ans = max(ans, n-i+1+mid);
            }

            if(pref_left[mid]<x)
                s=mid+1;

            else
                e = mid-1;
        }

    }
    cout<<ans<<"\n";
}

    
int main() {
    fastio();

    int t;
    cin>>t;

    while(t--)
        solve();
    
    return 0;
}