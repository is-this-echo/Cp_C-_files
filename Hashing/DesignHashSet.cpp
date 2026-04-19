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


class MyHashSet
{
public:
    MyHashSet() : hashTable(hashKey) {}

    void add(int key)
    {
        if (!contains(key))
        {
            int hash = key % hashKey;
            hashTable[hash].push_back(key);
        }
    }

    void remove(int key)
    {
        int hash = key % hashKey;
        auto itr = search(key, hash);

        if (itr != hashTable[hash].end())
            hashTable[hash].erase(itr);
    }

    bool contains(int key)
    {
        int hash = key % hashKey;
        return search(key, hash) != hashTable[hash].end();
    }

private:
    int hashKey{(int)1e6 + 1};
    vector<list<int>> hashTable;

    int hash(int key) { return key % hashKey; }

    list<int>::iterator search(int key, int hash)
    {
        return std::find(hashTable[hash].begin(), hashTable[hash].end(), key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */


int main()
{
    fastio();

    return 0;
}