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
    
 

class RandomizedSet {
public:
    RandomizedSet()
    {
        numbers.clear();
        idxMap.clear();
    }
    
    bool insert(int val)
    {
        if (idxMap.count(val) != 0)
            return false;
        
        numbers.emplace_back(val);
        idxMap[val] = numbers.size() - 1;
        return true;
    }
    
    bool remove(int val)
    {
        auto itr = idxMap.find(val);
        if (itr == idxMap.end())
            return false;
        
        size_t idx = itr->second;
        int lastVal = numbers.back();

        numbers[idx] = lastVal;
        idxMap[lastVal] = idx;

        numbers.pop_back();
        idxMap.erase(itr);
        return true;
    }
    
    int getRandom()
    {
        int randIdx = std::rand() % numbers.size();
        return numbers[randIdx];
    }

private:
    std::vector<int> numbers;
    std::unordered_map<int, size_t> idxMap;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

    
int main() {
    fastio();
    
    return 0;
}