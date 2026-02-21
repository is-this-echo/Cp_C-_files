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



struct Node
{
    string key;
    int val;
    Node(string key, int val) : key(key), val(val) {}
};

class LRUCache
{
public:
    LRUCache(size_t maxSize) : capacity(maxSize) {}

    int* get(string key) 
    {
        if (mp.count(key))
        {
            auto it =  mp[key];
            l.push_front(*it);
        // we need an iterator below not a Node*, use std::find to get iterator if
        // planning to use unordered_map<string, Node*> mp
            l.erase(it);

            mp[key] = l.begin();
            return &l.front().val;
        }
        return NULL;
    }

    void put(string key, int value) 
    {
        if (mp.count(key)) // if key already exists in the hashtable then update the key
        {
            auto it = mp[key];
            it->val = value;

            l.push_front(*it);
            l.erase(it);
            mp[key] = l.begin();
        }
        else // key not present in hash table, implement eviction policy and insert new key
        {
            // first need to check if cache is full or not
            // if it's at max capacity then remove the least recently used key
            if (l.size() == capacity)
            {
                Node lastElem = l.back();
                mp.erase(lastElem.key);
                l.pop_back();
            }
            Node n(key, value);
            l.push_front(std::move(n));
            mp[key] = l.begin();
        }
    }

    string mostRecentKey() 
    {
        return l.front().key;
    }

private:
    size_t capacity;
    list<Node> l;
    unordered_map<string, list<Node>::iterator> mp;
};


/*
Why your current code is NOT thread-safe
----------------------------------------
Your get() and put() both:
- mutate both lru (std::list), and listMap (unordered_map), and also move nodes (erase + push)

Problems under concurrency:
---------------------------
Data races on listMap and lru
Iterator invalidation
ABA issues if two threads move the same key
contains() + operator[] is not atomic

Without synchronization, undefined behavior.
Simplest correct solution: one mutex (coarse-grained)
This is the industry-default baseline and often good enough.

Idea:
-----
Protect all public operations with one std::mutex
get() is not read-only (it mutates LRU order), so it needs a lock too
*/
// Thread-safe and improved using list::splice()
class LRUCache
{
    int m_capacity;
    std::list<pair<int,int>> lru; // key, value
    unordered_map<int, std::list<pair<int,int>>::iterator> listMap;
    std::mutex mtx;

public:
    LRUCache(int capacity) : m_capacity(capacity){}

    int get(int key)
    {
        std::lock_guard<std::mutex> lock(mtx);
        if (listMap.contains(key))
        {
            auto itr = listMap[key];
            // This inserts the node (itr) at the start of the list before begin without copying
            lru.splice(lru.begin(), lru, itr);

            return listMap[key]->second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        std::lock_guard<std::mutex> lock(mtx);
        if (listMap.contains(key))
        {
            auto itr = listMap[key];
            itr->second = value;

            lru.push_front(*itr);
            lru.erase(itr);

            listMap[key] = lru.begin();
        }
        else
        {
            // check for capacity
            if (lru.size() == m_capacity)
            {
                auto itr = lru.back();
                listMap.erase(itr.first);
                lru.pop_back();
            }

            lru.push_front(pair<int,int>(key, value));
            listMap[key] = lru.begin();
        }
    }
};


/*
Higher-performance design (used in real systems)
------------------------------------------------
Option A — Sharded LRU
======================
Partition cache into N shards
Each shard has: its own mutex, its own LRU + map, Hash key → shard.
This is how Redis, Memcached, and many in-house trading caches work.

Option B — Read-optimized approximate LRU
=========================================
Don’t update LRU on every get
Track recency probabilistically
Batch updates
Used when: Reads ≫ writes, Strict LRU is not required


- The simplest correct approach is to protect both the map and list with a single mutex since get() mutates the LRU order. For higher concurrency, I’d shard the cache into multiple independent LRUs with per-shard locks. Fully lock-free LRU is impractical due to list mutations and iterator safety.
*/


/*
Can the LRU cache be made singleton? What could be the need to do so?
Ofcourse, it can be made a singleton.

1. Shared global state / shared cache
- I want all threads and components to see the same cache.
    ex : Client configuration cache, FX holiday calendar

2. Memory & capacity control
LRU caches are:
- capacity-bound
- memory-heavy (map + list + nodes)

Multiple instances = multiple independent eviction policies.
Singleton ensures:
------------------
- One global capacity limit
- Predictable memory usage

3. Consistency of eviction policy

- If each component has its own LRU:
Same key may exist in multiple caches
Evicted in one place but not another
Hard-to-reason performance behavior.


Yes, I can make it a Singleton using a Meyers Singleton for thread-safe initialization. Architecturally, an LRU cache is often a Singleton because it represents shared infrastructure state. Having a single instance ensures consistent eviction behavior, better cache hit rates, controlled memory usage, and avoids duplicate warm-ups. It also simplifies synchronization and observability. That said, I’d avoid Singleton if different components need different cache semantics or for better testability.
*/

class LRUCache
{
public:
    static LRUCache& instance() 
    {
        static LRUCache cache(1000); // thread-safe since C++11 and exactly one instance
        return cache;
    }

    int get(int key);
    void put(int key, int value);

private:
    LRUCache(int capacity) : m_capacity(capacity) {}

    int m_capacity;
    std::list<std::pair<int,int>> lru;
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> keyMap;
    std::mutex mtx;
};



int main() {
    fastio();

    LRUCache lEx(3);
    // cout << *lEx.get("s23_ultra") << endl;

    lEx.put("ps5", 20);
    lEx.put("s24_ultra", 12);

    cout << *lEx.get("ps5") << endl;

    lEx.put("iphone15_promax", 9);
    lEx.put("ps5", 6);
    lEx.put("iphone16_promax", 1);

    cout << lEx.mostRecentKey() << endl;

    auto ptr = lEx.get("s24_ultra");
    if (ptr)
        cout << *ptr << endl;
    else
        cout << "key doesn't exist!" << endl;

    return 0;
}