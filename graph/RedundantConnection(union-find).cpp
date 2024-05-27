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
    
 

/* 
brute-force approach ->  O(n^2) time complexity, since to form a cyclic graph we need 
atleast 3 edges, we can run a dfs from to check for cycle after every edge insertion (>=2 edges)
*/

class Solution2 {
    vector<int>ans;

    bool dfs(list<int>l[], vector<bool>&vis, int node, int parent){
        vis[node] = true;
        for(auto nbr : l[node]){
            if(!vis[nbr]){
                bool cycleFound = dfs(l,vis,nbr,node);
                if(cycleFound){
                    return true;
                }
            }
            else if(nbr != parent){
                return true;
            }
        }
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        list<int>l[n+1];

        for(auto edge : edges){
            l[edge[0]].push_back(edge[1]);
            l[edge[1]].push_back(edge[0]);

            vector<bool>vis(n+1, false);
            if(dfs(l,vis,edge[0],-1)){
                return edge;
            }
        }
        return {0,0};
    }
};

 /*
 optimized way -> union-find algorithm O(n) time complexity
 -----------------------------------------------------------------
*/

class Solution {
 
    int find(int node, vector<int>&parent){
        while(node != parent[node]) {
            node = parent[node];
        }
        return node;
    }

    bool customUnion(int x, int y, vector<int>&parent, vector<int>&rank) {
        int parx = find(x,parent);
        int pary = find(y,parent);

        // leads to a redundant connection
        if(parx == pary)
            return false;
        
        if(rank[parx] > rank[pary]){
            parent[pary] = parent[parx];
            rank[parx] += rank[pary];
        }
        
        else{
            parent[parx] = parent[pary];
            rank[pary] += rank[parx];
        }

        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n+1);
        vector<int>rank(n+1);

        for(int i=0; i<=n; i++){
            parent[i] = i;
            rank[i] = 1;
        }

        for(auto edge : edges){
            if(!customUnion(edge[0],edge[1],parent,rank))
                return edge;
        }
        return {0,0};
    }
}; 



int main() {
    fastio();
    
    return 0;
}