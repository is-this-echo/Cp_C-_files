#include<iostream>
#include<queue>
using namespace std;

#define ll long long
#define mod 1e9+7


void solve(){
    ll n, m;
    cin >> n >> m;

    vector<vector<int>> a(n,vector<int>(m));
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < m; j++){  
        cin >> a[i][j];
        pq.push(a[i][j]);
        }
    }

    ll i = 0;
    while (!pq.empty() && i < n){
        for (ll j = 0; j < m; j++){
            ll top = pq.top(); pq.pop();
            if (top != a[i][j])
            a[i][j] = top;
        }
        i++;
    }

    for (ll i = 0; i < n; i++){
        for(ll j=0;j<m;j++)
            cout<<a[i][j]<<" ";

        cout<<"\n";
    }
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    solve();

    return 0;
}