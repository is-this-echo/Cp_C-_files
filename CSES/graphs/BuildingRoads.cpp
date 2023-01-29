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
    

class Graph{
public:
    int v;
    list<int>*l;

    Graph(int d){
        v = d;
        l = new list<int>[v];
    }

    void addEdge(int x, int y, bool undir = true){
        l[x].push_back(y);

        if(undir){
            l[y].push_back(x);
        }
    }
};

void dfs(int node, Graph &g, vector<bool>&vis){
    vis[node] = true;

    for(auto nbr : g.l[node]){
        if(!vis[nbr]){
            dfs(nbr,g,vis);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;

    Graph g(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }

    int ans=0;
    vector<int>newPaths;
    vector<bool>vis(n+1,false);

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            newPaths.push_back(i);
            dfs(i,g,vis);
            ans++;
        }
    }

    cout<<ans-1<<"\n";
    for(int i=1;i<newPaths.size();i++){
        cout<<newPaths[0]<<" "<<newPaths[i]<<"\n";
    }
}
    
int main() {
    fastio();

    solve();

    return 0;
}