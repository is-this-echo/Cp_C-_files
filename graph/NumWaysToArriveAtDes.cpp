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


class Solution
{
    using ll = long long int;
public:
    int countPaths(int n, vector<vector<int>>& roads)
    {
        constexpr int mod = (int)(1e9 + 7);
        vector<vector<pair<int, int>>> adjl(n); // node -> (nbr, wt)

        for (const auto& edge : roads)
        {   // undirected graph so two sided edges
            adjl[edge[0]].emplace_back(edge[1], edge[2]);
            adjl[edge[1]].emplace_back(edge[0], edge[2]);
        }

        vector<pair<ll, int>> dist(n, {LLONG_MAX, 0}); // dist, count
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq; // min-heap (dist, node)

        dist[0] = {0, 1};
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto [currDist, node] = pq.top();
            pq.pop();

            // dist[node] will change on multiple iterations but not currDist
            // in the heap, so we avoid processing them as a shorter path
            // already has been processed
            if (currDist > dist[node].first)
                continue;

            for (auto [nbr, wt] : adjl[node])
            {
                ll newDist = (currDist + wt);
                if (newDist < dist[nbr].first)
                { 
                    // count will be the same as number of ways to arrive at the parent node
                    dist[nbr] = {newDist, dist[node].second};
                    pq.push({dist[nbr].first, nbr});
                }
                else if (newDist == dist[nbr].first)
                {
                    // we are able to reach to this node in shortest time 
                    // from more than one node, so add all the ways from both parent nodes
                    dist[nbr].second  = (dist[nbr].second + dist[node].second) % mod;
                }
            }
        }
        return dist[n-1].second;
    }
};


int main()
{
    fastio();
    
    return 0;
}