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
    


class MyHashMap
{
public:
    MyHashMap()
    {
        hashMap.resize(hashKey);
    }
    
    void put(int key, int value)
    {
        int hash = key % hashKey;
    
        if (auto itr = search(key, hash); itr != hashMap[hash].end())
            itr->second = value;
        else
            hashMap[hash].emplace_back(key, value);
    }
    
    int get(int key)
    {
        int hash = key % hashKey;
        if (auto itr = search(key, hash); itr != hashMap[hash].end())
        {
            return itr->second;
        }
        return -1;
    }
    
    void remove(int key)
    {
        int hash = key % hashKey;
        if (auto itr = search(key, hash); itr != hashMap[hash].end())
            hashMap[hash].erase(itr);
    }

private:
    int hashKey{(int) 1e6 + 7};
    std::vector<std::list<std::pair<int, int>>> hashMap; // key, value

    std::list<std::pair<int,int>>::iterator search(int key, int hash)
    {   
        return std::find_if(hashMap[hash].begin(), hashMap[hash].end(),
                            [&](const std::pair<int,int>&p)
                            {
                                return p.first == key;
                            });
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main()
{
    fastio();
    
    return 0;
}
