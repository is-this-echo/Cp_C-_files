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
    

using ii = pair<ll,ll>; 

void solve(){
    int n,m;
    cin >> n >> m;

    list<ii>l[n+1];
    ll x,y,w;
    for(int i=0; i<m; i++){
        cin >> x >> y >> w;
        l[x].push_back({w,y});
    }

    vector<ll>dist(n+1,INF);
    set<ii>st;

    dist[1] = 0;
    st.insert({dist[1],1});

    while(!st.empty()){
        auto itr = st.begin();
        ll disTillNow = itr->f;
        ll node = itr->s;

        st.erase(itr);

        for(auto nbrPair : l[node]){
            ll currDist = nbrPair.f;
            ll nbr = nbrPair.s;

            if(disTillNow + currDist < dist[nbr]){
                auto elem = st.find({dist[nbr], nbr});

                if(elem != st.end()){
                    st.erase(elem);
                }
                dist[nbr] = disTillNow + currDist;
                st.insert({dist[nbr], nbr});
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
}

    
int main() {
    fastio();

    solve();
    
    return 0;
}