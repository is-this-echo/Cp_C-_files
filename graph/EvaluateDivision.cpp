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


// class Solution {
// public:
//     vector<double> calcEquation(vector<vector<string>>& equations,
//                     vector<double>& values, vector<vector<string>>& queries)
//     {
//         // construct a weighted graph
//         vector<vector<pair<string, double>>> graph;
//         for (int i = 0; i < equations.size(); ++i)
//         {
            
//         }
//     }
// };


class Solution {
public:
    bool dfs(unordered_map<string, vector<pair<string, double>>>& graph, const string& curr,
                const string& target, unordered_set<string>& visited, double& ans, double rate)
    {
        if (curr == target)
        {
            ans = rate;
            return true;
        }

        visited.insert(curr);

        for (auto &[next, val] : graph[curr]) {
            if (!visited.count(next)) {
                if (dfs(graph, next, target, visited, ans, rate * val)) {
                    return true;
                }
            }
        }

        return false;
    }

    double convertRate(vector<vector<string>> &rates, vector<double> &values,
                       const string &from, const string &to)
    {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < rates.size(); i++)
        {
            string u = rates[i][0];
            string v = rates[i][1];
            double rate = values[i];

            graph[u].push_back({v, rate});
            graph[v].push_back({u, 1.0 / rate});
        }

        if (!graph.count(from) || !graph.count(to))
            return -1.0;

        unordered_set<string> visited;
        double ans = -1.0;

        dfs(graph, from, to, visited, ans, 1.0);
        return ans;
    }
};


class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;
    unordered_map<string, unordered_map<string, double>> cache;

    double dfs(const string &curr, const string &target, unordered_set<string> &visited)
    {
        if (cache[curr].count(target))
            return cache[curr][target];

        if (!graph.count(curr))
            return -1.0;

        if (curr == target)
            return cache[curr][target] = 1.0;

        visited.insert(curr);

        for (auto &[next, rate] : graph[curr])
        {
            if (visited.count(next)) continue;

            double result = dfs(next, target, visited);
            if (result != -1.0)
            {
                cache[curr][target] = rate * result;
                cache[target][curr] = 1.0 / cache[curr][target]; 
                return cache[curr][target];
            }
        }

        return cache[curr][target] = -1.0;
    }

    double convertRate(vector<vector<string>> &rates, vector<double> &values,
                       const string &from, const string &to)
    {
        for (int i = 0; i < rates.size(); i++) {
            string u = rates[i][0];
            string v = rates[i][1];
            double rate = values[i];

            graph[u].push_back({v, rate});
            graph[v].push_back({u, 1.0 / rate});
        }

        if (!graph.count(from) || !graph.count(to))
            return -1.0;

        unordered_set<string> visited;
        return dfs(from, to, visited);
    }
};


class Solution
{
public:
    double convertRate(vector<vector<string>> &rates, vector<double> &values,
                       const string &from, const string &to)
    {
        int n = rates.size();
        unordered_map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < n; ++i)
        {
            graph[rates[i][0]].emplace_back(rates[i][1], values[i]);
            graph[rates[i][1]].emplace_back(rates[i][0], 1.0 / values[i]);
        }

        if (!graph.count(from) || !graph.count(to))
            return -1.0;
        
        queue<pair<string, double>> q;
        unordered_set<string> visited;

        q.emplace(from, 1.0);
        visited.insert(from);

        while (!q.empty())
        {
            auto [curr, rate] = q.front();
            q.pop();

            if (curr == to)
                return rate;

            for (const auto& [nbr, value] : graph[curr])
            {
                if (visited.find(nbr) == visited.end())
                {
                    q.emplace(nbr, value * rate);
                    visited.insert(nbr);
                }
            }
        }
        return -1.0;
    }

};
    
int main()
{
    fastio();

    Solution s;
    vector<vector<string>> rates = {
        {"USD","JPY"}, {"USD","AUD"}, {"JPY","GBP"}
    };

    vector<double> values = {110, 1.45, 0.007};
    string from = "GBP";
    string to = "AUD";

    double ans = s.convertRate(rates, values, from, to);
    cout << fixed << setprecision(4) << ans << endl; // Output: 1.89

    return 0;
}