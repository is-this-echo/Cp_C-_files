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
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        // manager -> list of subordinates
        std::unordered_map<int, std::vector<int>> mp;

        for (int i = 0; i < n; ++i)
            mp[manager[i]].emplace_back(i);

        std::queue<pair<int,int>> q; // employee, time to reach news
        q.emplace(headID, 0);

        int ans = 0;
        while (!q.empty())
        {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i)
            {
                const auto [emp, reachTime] = q.front();
                q.pop();
                ans = max(ans, reachTime);

                for (const auto& sub : mp[emp])
                {
                    q.emplace(sub, reachTime + informTime[emp]);
                }
            }
        }
       return ans; 
    }
};


int main() {
    fastio();
    
    return 0;
}