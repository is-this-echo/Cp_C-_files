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
    

// Min grps to not intersect = number of overlaps for the ranges.
// Sweepline technique, meeting cannot start and end at the same time.
// Modify the end time to finish in the next cell, which means if we have
// [1, 5] and [5, 8], then at time = 5, we have an intersection or 2 meetings running.
class Solution
{
    using ll = long long;
public:
    int minGroups(vector<vector<int>>& intervals)
    {   
        int MAX_SIZE = 1e6 + 2;
        std::vector<int> timeline(MAX_SIZE, 0);

        for (const auto& interval : intervals)
        {
            ++timeline[interval[0]];
            --timeline[interval[1] + 1];
        }

        // accumulate
        int minGrps = 0;
        for (int i = 1; i < MAX_SIZE; ++i)
        {
            timeline[i] += timeline[i - 1];
            minGrps = max(minGrps, timeline[i]);
        }

        return minGrps;
    }
};

    
int main() {
    fastio();
    
    return 0;
}