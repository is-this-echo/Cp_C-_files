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
    
 

void partition(vector<int>&ans, int n, int sum){
    assert(n>=0 && sum>=0);

    if(n==0 || sum==0)
        return;
    
    if(n>sum)
        partition(ans,n-1,sum);

    else{
        ans.push_back(n);
        partition(ans, n-1, sum-n);
    }
}


void solve(){
    int n,x,y;
    cin>>n>>x>>y;

    ll sum = (n*n + n)/2;
    // ll req = x*sum/(x+y);

    if(sum%(x+y)!=0){
        cout<<"IMPOSSIBLE"<<"\n";
        return;
    }


    vector<int>ans;
    ll req = x*sum/(x+y);

    partition(ans,n,req);

    int si = ans.size();
    cout<<"POSSIBLE"<<"\n";
    cout<<si<<"\n";

    for(int i=0;i<si;i++)
        cout<<ans[i]<<" ";
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