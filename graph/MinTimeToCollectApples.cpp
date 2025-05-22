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
    int dfs(int node, int parent, vector<vector<int>>& graph, 
                vector<bool>& hasApples)
    {
        int time = 0;
        for (int nbr : graph[node])
        {
            if (nbr != parent)
            {
                int childTimeTaken = dfs(nbr, node, graph, hasApples);
                if (childTimeTaken > 0 || hasApples[nbr])
                    time += (childTimeTaken + 2); 
            }
        }
        return time;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple)
    {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }

        return dfs(0, -1, graph, hasApple);
    }
}; 

 
int main() {
    fastio();
    
    return 0;
}