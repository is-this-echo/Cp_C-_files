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