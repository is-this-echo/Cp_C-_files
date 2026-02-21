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


struct Tick
{
    long long timestamp; // in milliseconds
    double price;
};


class StockAlertSystem
{
public:
    StockAlertSystem(long long windowSizeMs, double thresholdPct)
        : windowSize(windowSizeMs), thresholdPct(thresholdPct) {}

    void processTick(long long timestamp, double price)
    {
        Tick newTick{timestamp, price};

        // 1. Evict expired ticks from the main queue
        while (!ticks.empty() && ticks.front().timestamp <= timestamp - windowSize)
        {
            Tick old = ticks.front();
            ticks.pop_front();

            // If the expired tick is also at the front of minDeque, remove it
            if (!minDeque.empty() && minDeque.front().timestamp == old.timestamp)
                minDeque.pop_front();

            // If the expired tick is also at the front of maxDeque, remove it
            if (!maxDeque.empty() && maxDeque.front().timestamp == old.timestamp)
                maxDeque.pop_front();
        }

        // 2. Insert new tick into ticks queue
        ticks.push_back(newTick);

        // 3. Maintain minDeque: pop all elements larger than current price
        while (!minDeque.empty() && minDeque.back().price >= price)
            minDeque.pop_back();

        minDeque.push_back(newTick);

        // 4. Maintain maxDeque: pop all elements smaller than current price
        while (!maxDeque.empty() && maxDeque.back().price <= price)
            maxDeque.pop_back();

        maxDeque.push_back(newTick);

        // 5. Get current min and max price in the last Y minutes
        double minPrice = minDeque.front().price;
        double maxPrice = maxDeque.front().price;

        // 6. Check percentage change condition
        double pctChange = ((maxPrice - minPrice) / minPrice) * 100.0;

        if (pctChange >= thresholdPct)
        {
            cout << "[ALERT] Significant price change detected!" << endl;
            cout << "    Min price = " << minPrice
                 << ", Max price = " << maxPrice
                 << ", Change = " << pctChange << "%\n";
        }
    }

private:
    long long windowSize; // in milliseconds
    double thresholdPct;  // X, in percentage

    deque<Tick> ticks;      // store all ticks in the current window
    deque<Tick> minDeque;   // increasing prices
    deque<Tick> maxDeque;   // decreasing prices
};


int main()  
{
    fastio();

    // Create a system with a 10-minute window and a 5% threshold
    StockAlertSystem system(10 * 60 * 1000, 5.0);

    // Simulate tick stream
    vector<pair<long long, double>> stream = {
        {1000, 100.0}, {2000, 101.0}, {3000, 105.0},
        {4000, 107.0}, {5000, 96.0},  {7000, 95.0}
    };

    for (auto &tick : stream)
        system.processTick(tick.first, tick.second);

    return 0;
}
