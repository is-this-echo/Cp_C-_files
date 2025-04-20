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
    using ll = long long;
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> fqMap; // node, freq
        for (int i = 0; i < roads.size(); ++i)
        {
            fqMap[roads[i][0]]++;
            fqMap[roads[i][1]]++;
        }

        priority_queue<ll> pq;
        for (const auto& [node, freq] : fqMap)
            pq.push(freq);
        
        ll importance = 0;
        ll value = n;
        while (!pq.empty())
        {
            importance += pq.top() * value;
            value--;
            pq.pop();
        }
        return importance;
    }
};


int main() {
    fastio();
    
    return 0;
}