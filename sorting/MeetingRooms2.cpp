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

// Sweepline technique, meeting can start and end at the same index (inclusive).
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals)
    {
        int MAX_LENGTH = 1e6;
        vector<int> timeline(MAX_LENGTH, 0);

        for (const auto& interval : intervals)
        {
            timeline[interval[0]]++;
            timeline[interval[1]]--;
        }

        int meetingRooms = 0;
        for (int i = 1; i < MAX_LENGTH; ++i)
        {
            timeline[i] += timeline[i-1];
            meetingRooms = max(meetingRooms, timeline[i]);
        }
        return meetingRooms;
    }
};


// By sorting and keeping 2 separate vectors for start and end times.
// We keep 2 ptrs to keep track of start and end times and when
// start < end, increment count and shift start ptr to right,
// when start == end time, we decrement count and then shift end ptr to right,
// continue doing this till start ptr reached end.
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals)
    {   
        int n = intervals.size();
        std::vector<int> start(n, 0), end(n, 0);
        for (int i = 0; i < n; ++i)
        {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }

        std::ranges::sort(start);
        std::ranges::sort(end);

        int startPtr = 0, endPtr = 0;
        int count = 0, maxCount = 0;
        while (startPtr < n)
        {
            if (start[startPtr] < end[endPtr])
            {
                ++count;
                maxCount = max(maxCount, count);

                startPtr++;
            }
            else
            {
                --count;
                endPtr++;
            }
        }

        return maxCount;
    }
};


int main()
{
    fastio();

    Solution st;
    std::vector<std::vector<int>> input{{0,30}, {5,10}, {15,20}};

    std::cout << st.minMeetingRooms(input);
    
    return 0;
}