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
public:
    long long minimumWeight(int n, vector<vector<int>>& edges,
                            int src1, int src2, int dest)
    {
        // min(dist(src1, x)  + dist(src2, x) + dist(des, x)), src1 and src2 meets at x
        vector<vector<pair<long,long>>> graph(n), revGraph(n);
        for (const auto& edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1], edge[2]); // node -> nbr, wt
            revGraph[edge[1]].emplace_back(edge[0], edge[2]);
        }

        vector<long> minDistSrc1(n, LONG_MAX);
        vector<long> minDistSrc2(n, LONG_MAX);
        vector<long> minDistDest(n, LONG_MAX);

        auto djikstra = [&](int src, vector<vector<pair<long,long>>>& graph, vector<long>& dist)
        {
            priority_queue<pair<long,long>, vector<pair<long,long>>, greater<>> pq; // dist, node
            dist[src] = 0;
            pq.emplace(0, src);

            while (!pq.empty())
            {
                auto [currDist, currNode] = pq.top();
                pq.pop();

                if (currDist > dist[currNode])
                    continue;

                for (const auto& [nbr, wt]: graph[currNode])
                {
                    if (currDist + wt < dist[nbr])
                    {
                        dist[nbr] = currDist + wt;
                        pq.emplace(dist[nbr], nbr);
                    }
                }
            } 
        };

        djikstra(src1, graph, minDistSrc1);
        djikstra(src2, graph, minDistSrc2);
        djikstra(dest, revGraph, minDistDest);

        long ans = LONG_MAX;
        for (int i = 0; i < n; ++i)
        {
            if (minDistSrc1[i] == LONG_MAX || minDistSrc2[i] == LONG_MAX
                || minDistDest[i] == LONG_MAX)
                continue;

            ans = min(ans, minDistSrc1[i] + minDistSrc2[i] + minDistDest[i]);
        }

        return ans == LONG_MAX ? -1 : ans;
    }
};


int main()
{
    fastio();

    return 0;
}