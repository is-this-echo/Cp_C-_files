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
    int n, m;
    cin >> n >> m;

    list<int>l[n+1];
    int x,y;

    for(int i=0; i<m; i++){
        cin >> x >> y;
        l[x].push_back(y);
        l[y].push_back(x);
    }

    queue<int>q;
    vector<bool>vis(n+1,false);
    vector<int>dist(n+1,-1), parent(n+1, -1);

    parent[1] = 1; dist[1] = 0;
    vis[1] = true;
    q.push(1);

    while(!q.empty()){
        int currNode = q.front();
        q.pop();

        for(int nbr : l[currNode]){
            if(!vis[nbr]){
                q.push(nbr);
                vis[nbr] = true;
                parent[nbr] = currNode; dist[nbr] = 1 + dist[currNode];
            }
        }
    }
    if(dist[n] == -1){
        cout << "IMPOSSIBLE" << "\n";
        return;
    }

    cout << dist[n] + 1 << endl;

    vector<int>path;
    int temp = n;

    while(temp!=1){
        path.push_back(temp);
        temp = parent[temp];

    }
    path.push_back(1);

    for(int i=path.size()-1 ; i>=0; i--){
        cout << path[i] <<" ";
    }
    cout << endl;
}

    
int main() {
    fastio();

    solve();
    
    return 0;
}