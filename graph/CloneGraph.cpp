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
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    // The purpose of dfs() is to create a clone node or return if it already exists
    // for an original node.
    Node* dfs(Node* node, std::unordered_map<Node*, Node*>& mp)
    {
        if (mp.count(node))
            return mp[node];

        Node* cloneNode = new Node(node->val);
        mp[node] = cloneNode;

        for (const auto& nbr : node->neighbors)
            cloneNode->neighbors.emplace_back(dfs(nbr, mp));

        return cloneNode;
    }

public:
    Node* cloneGraph(Node* node)
    {
        if (!node)
            return node;

        std::unordered_map<Node*, Node*> mp; // original, clone
        return dfs(node, mp);
    }
};


// A shorter dfs solution
class Solution
{
public:
    unordered_map<Node*, Node*> m;
    Node* cloneGraph(Node* node)
    {
        if (!node)
            return nullptr;

        if (m.find(node) == m.end())
        {
            m[node] = new Node(node->val, {});

            for (auto a : node->neighbors)
                m[node]->neighbors.push_back(cloneGraph(a));

        }
        return m[node];
    }
};


// Bfs approach
class Solution {
public:
    Node* cloneGraph(Node* node)
    {
        if (!node)
            return node;

        std::queue<Node*> q;
        std::unordered_map<Node*, Node*> visited; // original, clone

        q.push(node);
        visited[node] = new Node(node->val);

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            for (const auto& nbr : curr->neighbors)
            {
                // If cloned version of nbr doesn't exist create one,
                // add nbr of original node to queue.
                if (!visited[nbr])
                {
                    visited[nbr] = new Node(nbr->val);
                    q.emplace(nbr);
                }
                // Set the nbr of cloned version of current node.
                visited[curr]->neighbors.emplace_back(visited[nbr]);
            }
        }
        return visited[node];
    }
};

    
int main() {
    fastio();
    
    return 0;
}