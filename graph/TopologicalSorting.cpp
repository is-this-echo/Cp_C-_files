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
    int V;
    list<int> *l;

public:
    Graph(int V) : V(V), l(new list<int> [V]) {}

    void addEdge(int x, int y, bool undir = false)
    {
        l[x].push_back(y);
        if(undir)
            l[y].push_back(x);
    }

    void topologicalSort()
    {
        // calculate the indgree(incoming edges) for every node
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; ++i)
        {
            for (auto nbr : l[i])
                indegree[nbr]++;
        }

        // push all nodes with indegree of 0 to the queue for bfs, it means these nodes have no dependencies
        queue<int> q;
        for (int i = 0; i < V; ++i)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            auto currNode = q.front();
            q.pop();

            cout << currNode << " ";

            // 
            for (auto nbr : l[currNode])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
    }
};


int main()
{
    Graph g(6);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(1, 4);
    g.addEdge(1, 2);

    g.topologicalSort();

    return 0;
}