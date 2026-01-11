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


// BFS approach, TC = O(V+E), SC = O(V), V -> number of nodes and E -> number of edges
class Solution
{
    bool bfs(vector<vector<int>>& graph, vector<int>& color, int node)
    {
        if (color[node] != -1)
            return true;

        queue<int> q;
        q.emplace(node);

        // We can start with any color here as this node is disconnected from the rest of the graph.
        // If this node was explored by some other path then it wouldn't have been -1 aka un-colored.
        color[node] = 0;

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            for (const auto& nbr : graph[curr])
            {
                if (color[nbr] == -1)
                {
                    color[nbr] = !color[curr]; // (color[nbr] = color[curr] + 1) % 2;
                    q.emplace(nbr);
                }
                else if (color[nbr] == color[curr])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph)
    {   
        int n = graph.size();
        vector<int> color(n, -1); // -1 means not visited, colors are 0 or 1

        for (int i = 0; i < n; ++i)
            if (!bfs(graph, color, i))
                return false;

        return true;
    }
};

// DFS approach, TC = O(V+E), SC = O(V), V -> number of nodes and E -> number of edges
// We can't have a base case in the dfs function to return true if node is colored because
// unlike bfs dfs doesn't ensure that bipartite policy is violated.
class Solution
{

    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node)
    {
        for (const auto& nbr : graph[node])
        {
            if (color[nbr] == -1)
            {
                color[nbr] = !color[node];
                if (!dfs(graph, color, nbr))
                    return false;
            }
            else if (color[nbr] == color[node])
            {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph)
    {   
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; ++i)
        {
            if (color[i] == -1)
            {
                color[i] = 0;

                if (!dfs(graph, color, i))
                    return false;
            }

        }
        return true;
    }
};


int main()
{
    fastio();
    
    return 0;
}