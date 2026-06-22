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
public:
    int maxEvents(vector<vector<int>>& events)
    {
        /*
        For each day:
        Add all events that start on that day to a min-heap ordered by end day.
        Remove events whose end day has already passed.
        Attend the event with the smallest end day.
        */
        std::ranges::sort(events);

        int lastDay = 1;
        for (const auto& event : events)
            lastDay = max(lastDay, event[1]);

        int attended = 0;
        int i = 0, n = events.size();
        std::priority_queue<int, vector<int>, greater<>> pq;

        for (int day = 1; day <= lastDay; ++day)
        {
            while (i < n && events[i][0] == day)
            {
                pq.push(events[i][1]);
                ++i;
            }

            while (!pq.empty() && pq.top() < day)
                pq.pop();

            if (!pq.empty())
            {
                pq.pop();
                ++attended;
            }
        }
        return attended;
    }
};


int main()
{
    fastio();
    
    return 0;
}
