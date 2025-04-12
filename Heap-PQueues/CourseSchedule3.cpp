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
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), [&](const vector<int>& a,
                                                    const vector<int>& b)
        {
            return a[1] < b[1];
        });

        priority_queue<int> pq; // max heap to store duration of courses
        int currDay = 0;
        // idea is to be greedy and decrease the currDay while
        // accumulating more number of courses
        for (int i = 0; i < n; ++i)
        {   int duration = courses[i][0];
            int lastDay = courses[i][1];

            if (duration > lastDay)
                continue;

            if (currDay + duration <= lastDay)
            {
                pq.push(duration);
                currDay += duration;
            }
            else
            {
                if (!pq.empty())
                {
                    int maxExistingDuration = pq.top();
                    if ((maxExistingDuration > duration) &&
                        (currDay - maxExistingDuration + duration) <= lastDay)
                    {
                        currDay -= maxExistingDuration;
                        pq.pop();
                        pq.push(duration);
                        currDay += duration;
                    }
                }
            }
        }
        return pq.size();
    }
};


int main() {
    fastio();

    return 0;
}