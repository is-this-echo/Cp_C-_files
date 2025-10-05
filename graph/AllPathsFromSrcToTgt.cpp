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
    void dfs(int node, vector<vector<int>>& graph, vector<vector<int>>& ans,
                vector<int>& temp, int n)
    {
        if (node == n)
        {
            ans.emplace_back(temp);
            return;
        }

        for (int nbr : graph[node])
        {
            temp.emplace_back(nbr);
            dfs(nbr, graph, ans, temp, n);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> temp{0};

        dfs(0, graph, ans, temp, n - 1);
        return ans;    
    }
};


int main() {
    fastio();


    return 0;
}