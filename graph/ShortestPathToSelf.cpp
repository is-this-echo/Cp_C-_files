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
    Shortest-cycle problem on a directed weighted graph.
    Problem Restatement (in simple terms) : 

    You have a directed graph with up to 1000 nodes and edges.
    For each node x, find the shortest cycle that starts and ends at x.
    A cycle must have length ≥ 1
    If no cycle exists for x, return 0
*/

vector<int> getMinimumLength(int road_nodes, vector<int> roads_from, vector<int> roads_to, vector<int> roads_weight)
{
    // 1-indexed node numbering
    const ll INF = 1e18;
    int n = road_nodes;
    int m = roads_from.size();

    vector<vector<pair<int,int>>> graph(n + 1); // directed graph
    for (int i = 0; i < m; i++)
        adj[roads_from[i]].push_back({roads_to[i], roads_weight[i]});

        /*
            Run Dijkstra algo from each node as source to find the shortest distance
            to all other nodes (SSSP). Then we go through all the edges which
            comes back to source node, add the weight of the edge which comes back to
            source and then take the minimum among them to be the result.
            If no edge comes back to source node or the shortest path to that node
            is INF, then set result as 0.

        */
    vector<int> result(n + 1, 0);
    for (int src = 1; src <= n; ++src)
    {
        vector<ll> dist(n + 1, INF);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

        dist[src] = 0;
        pq.emplace(0, src);

        while (!pq.empty())
        {
            auto [currDist, node] = pq.top();
            pq.pop();

            if (currDist > dist[node])
                continue;

            for (const auto& [nbr, weight] : adj[u])
            {
                if (dist[nbr] > currDist + weight)
                {
                    dist[nbr] = currDist + weight;
                    pq.emplace(dist[nbr], nbr);
                }
            }
        }

        ll best = INF;

        // Look for edges coming back to source node
        for (int i = 0; i < m; ++i)
        {
            if (roads_to[i] == src)
            {
                if (int fromNode = roads_from[i], dist[fromNode] != INF)
                    best = min(best, dist[fromNode] + roads_weight[i]);
            }
        }

        result[src] = (best == INF ? 0 : (int)best);
    }

    // Remove index 0 to match output format
    result.erase(result.begin());
    return result;
}


int main()
{
    fastio();
    
    return 0;
}