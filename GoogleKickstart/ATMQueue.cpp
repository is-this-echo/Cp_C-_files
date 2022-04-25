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
    int n,x;
    cin>>n>>x;

    vector<pair<int,int>>arr(n);
    int amt;

    for(int i=0;i<n;i++){
        cin>>amt;

        int turns = ((amt%x==0)? amt/x : amt/x + 1);
        arr[i] = {turns,i+1};
    }

    sort(arr.begin(), arr.end(), [&](const  pair<int,int>a, const pair<int,int>b){
        if(a.f==b.f)
            return a.s < b.s;
        
        return a.f < b.f;
    });

    for(auto i : arr)
        cout<<i.s<<" ";
    
    cout<<"\n";

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