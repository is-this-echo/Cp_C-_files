// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

#define ll long long
#define F first
#define S second

const int N = 100010, mod = 1e9+7;

vector<vector<int>> g;
int n, m;

int exp(int x, int n, int mod) {
    int ans = 1;
    while(n) {
        if(n&1)
            ans = 1LL*ans*x%mod;
        x = 1LL*x*x%mod;
        n >>= 1;
    }
    return ans;
}

vector<int> dfs(int v, int p=0) {
    vector<int> ans (m+1, 1);
    for(int u: g[v]) {
        if(u==p)
            continue;
        vector<int> cur = dfs(u, v);
        for(int x=1; x<=m; x++) {
            for(int y=1; y<=m; y++) {
                if(__gcd(x, y)==1)
                    ans[x] = 1LL*ans[x]*cur[y]%mod;
            }
        }
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    g.resize(n+1);
    int u, v;
    for(int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n==1) {
        cout << 1 << '\n';
        return;
    }
    int ans = 0;
    for(int x: dfs(1)) {
        ans += x;
        if(ans>=mod)
            ans -= mod;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // int _t; cin >> _t; while(_t--)
    solve();
}
