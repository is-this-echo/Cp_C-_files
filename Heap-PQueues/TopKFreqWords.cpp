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
    using elem = pair<int, string>;

    class Compare
    {
    public:
        bool operator()(const elem& a, const elem& b)
        {
            if (a.first == b.first)
                return a.second < b.second;

            return a.first > b.first;
        }
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        unordered_map<string, int> freqMap;
        for (const auto& word : words)
            freqMap[word]++;

        priority_queue<elem, vector<elem>, Compare> pq; // min-heap
        for (const auto& [word, freq] : freqMap)
        {
            pq.emplace(freq, word);
            if (pq.size() > k)
                pq.pop();
        }

        vector<string> ans;
        while (!pq.empty())
        {
            const auto [freq, word] = pq.top();
            pq.pop();
            ans.emplace_back(word);
        }

        std::ranges::reverse(ans);
        return ans;
    }
};


int main()
{
    fastio();
    
    return 0;
}