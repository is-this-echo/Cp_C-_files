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
    
 
class Solution {
    bool dfs(int i, vector<vector<int>>&graph, vector<bool>&ans,
                    vector<bool>&vis){

        if(graph[i].size()==0)
            return true;

        vis[i] = true;
        for(auto nbr : graph[i])
        {
            if(vis[nbr]) return false;
            if(ans[nbr]) continue;

            bool isSafe = dfs(nbr,graph,ans,vis);

            if(!isSafe)
                return false;
        }
        ans[i] = true;
        vis[i] = false;
        
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>ans(n,false);
        vector<bool>vis(n,false);

        for(int i=0; i<n; i++){
            if(dfs(i,graph,ans,vis) == true){
                ans[i] = true;
            }
        }
        
        vector<int>out;
        for(int i=0; i<n; i++){
            if(ans[i]==true)
                out.push_back(i);
        }
        return out;
    }
};
    
int main() {
    fastio();

    vector<vector<int>>aa = {{1,2},{2,3},{5},{0},{5},{},{}};
    Solution st;
    auto pp = st.eventualSafeNodes(aa);

    for(auto x : pp){
        cout<<x<<", ";
    }

    return 0;
}