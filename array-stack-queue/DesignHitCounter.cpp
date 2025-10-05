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
    
 

//OJ: https://leetcode.com/problems/design-hit-counter/
// Time:
//      HitCounter: O(1)
//      hit, getHits: amortized O(1)
// Space: O(N)
class HitCounter
{
public:
    HitCounter() {}
    void hit(int timestamp)
    {
        clear(timestamp);
        q.push(timestamp);
    }

    int getHits(int timestamp)
    {
        clear(timestamp);
        return q.size();
    }

private:
    void clear(int timestamp)
    {
        int start = timestamp - 300;
        while (q.size() && q.front() <= start) q.pop();
    }

    queue<int> q;
};

/*
Follow-up Question

"What if the number of hits per second could be huge? Does your design scale?"
This is where your current design struggles.

Problem with Current Design
If you get millions of hits per second, your queue will hold millions × 300 ≈ 300M timestamps in the worst case.
That’s memory-heavy and not scalable.

Better Scalable Approaches
We need to compress the storage.
Approach — Bucket Compression

Instead of storing every hit's timestamp, we bucket hits by second.
Idea:
Use a fixed-size array of 300 buckets.

Each bucket stores:
timestamp → when the bucket was last updated.
count → number of hits at that timestamp.

When a hit arrives:
Compute idx = timestamp % 300.
If bucket[idx].timestamp == timestamp → increment count.
Else → reset bucket[idx] to {timestamp, 1}.
When querying getHits(timestamp):
Sum counts of buckets where timestamp - bucket[i].timestamp < 300.

Complexity
Time:
hit() → O(1).
getHits() → O(300) ≈ O(1).
Space: O(300) ≈ O(1). ✅ Much better than O(N).

“Currently, my solution stores one entry per hit, so if we have millions of hits per second, memory usage explodes.
To scale better, we can bucket hits per second since we only care about counts within a 300s sliding window.
This way, we only maintain 300 buckets at any time, making both time and space constant — O(1).
If we need even more scalability, we can distribute buckets across servers and aggregate counts asynchronously.”
*/

class HitCounter {
public:
    HitCounter() : buckets(300) {}

    void hit(int timestamp)
    {
        int idx = timestamp % 300;
        if (buckets[idx].timestamp == timestamp)
        {
            buckets[idx].count++;
        }
        else
        {
            buckets[idx].timestamp = timestamp;
            buckets[idx].count = 1;
        }
    }

    int getHits(int timestamp)
    {
        int total = 0;
        for (auto &b : buckets)
            if (timestamp - b.timestamp < 300)
                total += b.count;

        return total;
    }

private:
    struct Bucket
    {
        int timestamp = 0;
        int count = 0;
    };

    vector<Bucket> buckets;
};


int main() {
    fastio();
    
    return 0;
}