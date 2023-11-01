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



int start=-1;
int ed=-1;

bool dfs(list<int>l[], vector<int>&parent, vector<bool>&vis, int node, int par){
    vis[node] = true;
    parent[node] = par;

    for(auto nbr : l[node]){
        if(!vis[nbr]){
            bool cycleFound = dfs(l,parent,vis,nbr,node);

            if(cycleFound)
                return true;
        }
        else if(nbr != par && par != -1){
            start = nbr, ed = node;
            return true;
        }
    }
    return false;
}
 

void solve(){
    int n,m;
    cin >> n >> m;

    list<int>l[n+1];
    for(int i = 0; i<m; i++){
        int x,y;
        cin >> x >> y;

        l[x].push_back(y);
        l[y].push_back(x);
    }

    vector<bool>vis(n+1,false);
    vector<int>parent(n+1,-1);

    for(int i=1; i<=n; i++){
        bool res = dfs(l,parent,vis,i,-1);
        if(res){
            vector<int>ans;
            int temp = ed;
            ans.push_back(start);

            while(temp!=start){
                ans.push_back(temp);
                temp = parent[temp];
            }
            ans.push_back(start);
            cout << ans.size() << endl;

            for(auto x : ans)
                cout << x << " ";

            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
    

int main() {
    fastio();

    solve();
    
    return 0;
}