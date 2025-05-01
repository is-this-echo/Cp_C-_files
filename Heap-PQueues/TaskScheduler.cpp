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
    int leastInterval(vector<char>& tasks, int n)
    {
        map<char, int> mp;
        for (const auto& ch : tasks)
            mp[ch]++;

        priority_queue<int> pq; // max heap to store freq
        for (const auto& [ch, freq] : mp)
            pq.push(freq);

        int idx = 0; // index of task array
        queue<pair<int,int>> q; // freq, nextIdx
        while (!pq.empty() || !q.empty())
        {
            idx++;
            if (!pq.empty())
            {
                int freq = pq.top();
                pq.pop();
                freq--;

                if (freq > 0)
                    q.push({freq, idx + n});
            }

            // no two tasks can have same time of next occurrence as 
            // n is same for all and so is idx+n, so only one
            // element can match the if condition at any given idx
            if (!q.empty() && idx == q.front().second)
            {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return idx;
    }
}; 


int main() {
    fastio();
    
    return 0;
}
