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
    

// dp[i].f  -> sum till now
// dp[i].s -> min. till now 

pair<ll,ll>dfs(vector<int>adj[], vector<pair<ll,ll>>&dp, vector<int>&f, int cur){
    if(adj[cur].size()==0){
        dp[cur].f = f[cur] ;
        dp[cur].s = f[cur];

        return dp[cur];
    }

    dp[cur].f = 0;
    dp[cur].s = INT_MAX;

    for(int i : adj[cur]){
        pair<ll,ll>temp = dfs(adj,dp,f,i);
        dp[cur].f += temp.f;
        dp[cur].s = min(dp[cur].s, temp.s);
    }

    if(dp[cur].s < f[cur]){
        dp[cur].f  = dp[cur].f - dp[cur].s + f[cur];
        dp[cur].s = f[cur];
    }

    return dp[cur];
}


void solve(){
    int n;
    cin>>n;

    // f[0] = abyss
    vector<int>f(n+1);
    f[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }

    vector<int>adj[n+1];
    vector<int>p(n+1);

    for(int i=1;i<=n;i++){
        cin>>p[i];
        adj[p[i]].push_back(i);
    }

    vector<pair<ll,ll>>dp(n+1);

    for(int i=0;i<=n;i++){
        dp[i].f = 0;
        dp[i].s= 0;
    }

    dfs(adj, dp, f, 0);

    cout<<dp[0].f<<"\n";
    
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