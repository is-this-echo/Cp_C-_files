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
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int>indegree(numCourses, 0);
        vector<vector<int>> adjl(numCourses);
        for (auto edges : prerequisites)
        {
            adjl[edges[1]].emplace_back(edges[0]);
            indegree[edges[0]]++;
        }

        vector<int>order;
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            order.emplace_back(curr);

            for (int nbr : adjl[curr])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        return order.size() == numCourses ? order : vector<int>{};
    }
};


int main() {
    fastio();
    
    return 0;
}