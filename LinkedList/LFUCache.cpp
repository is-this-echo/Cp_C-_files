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
    
 

class LFUCache {
public:
    LFUCache(int capacity) : capacity_(capacity), minFreq_(0) {}

    int get(int key)
    {
        if (keyMap.contains(key))
        {
            int val = keyMap[key].value;
            updateFreq(key);

            return val;
        }   
        return -1;
    }

    void put(int key, int value)
    {
        if (keyMap.contains(key))
        {
            keyMap[key].value = value;
            updateFreq(key);
        }
        else
        {
            if (keyMap.size() == capacity_)
            {
                int evictKey = freqMap[minFreq_].back();
                keyMap.erase(evictKey);
                freqMap[minFreq_].pop_back();
            }

            freqMap[1].push_front(key);
            keyMap[key] = {value, 1, freqMap[1].begin()};
            minFreq_ = 1;
        }
    }

private:
    struct Node; // forward declaration

    int capacity_;
    int minFreq_;
    unordered_map<int, Node> keyMap; // key, node (unique to each key)
    unordered_map<int, std::list<int>> freqMap; // freq, list of keys

    struct Node
    {
        int value;
        int freq;
        std::list<int>::iterator listRef;

    };

    void updateFreq(int key)
    {
        auto listRef = keyMap[key].listRef;
        int freq = keyMap[key].freq;

        freqMap[freq].erase(listRef);

        if (freqMap[freq].empty() && freq == minFreq_)
        {
            freqMap.erase(freq); // just to be safe, avoid empty list
            ++minFreq_;
        }

        freqMap[freq + 1].push_front(key);
        keyMap[key].freq++;
        keyMap[key].listRef = freqMap[freq + 1].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
    
int main()
{
    fastio();
    
    return 0;
}