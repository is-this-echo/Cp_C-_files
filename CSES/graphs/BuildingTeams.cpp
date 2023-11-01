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
    
 

list<int>l[100002];

bool dfs(int node, int col, vector<int>&color){
    color[node] = col;

    for(int nbr : l[node]){
        if(!color[nbr]){
            bool res = dfs(nbr,col^3,color);

            if(!res){
                return false;
            }
        }
        if(color[nbr] == color[node])
            return false;
    }
    return true;
}


void solve(){
    int n,m;
    cin >> n >> m;

    int x,y;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        l[x].push_back(y);
        l[y].push_back(x); 
    }

    vector<int>color(n+1,0);

    // color : 0->uncoloured, 1->red, 2->blue
    for(int i=1; i<=n; i++){
        if(!color[i]){
            bool ans = dfs(i,1,color);
            if(!ans){
                cout << "IMPOSSIBLE" <<endl;
                return;
            }
        }
    }

    for(int i=1; i<=n; i++)
        cout << color[i] << " ";
    
    cout << endl;
}
    

int main() {
    fastio();

    solve();
    
    return 0;
}