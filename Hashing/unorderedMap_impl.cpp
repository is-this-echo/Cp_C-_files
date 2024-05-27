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
    
 

class unordered_map {
    private:
        list<pair<int,int>>*buckets;
        int bucket_size;
        int total_elements;
        int max_load_factor;

        int hash(int key){
            int hashed_key = someHashFunction(key);
            int idx = hashed_key % bucket_size;
        }

        void reHashIfNeeded(){
            if(total_elements/bucket_size <= max_load_factor){
                return;
            }
            bucket_size *= 2;
            auto new_buckets = new list<pair<int,int>>[bucket_size];
            for(int i=0; i<bucket_size/2; i++){
                for(auto &kv_it : buckets[i]){
                    new_buckets[hash(kv_it->first)].push_back(*kv_itr);
                }
            }
            delete[] buckets;
            buckets = new_buckets;
        }

    public:
        list<int>::iterator find(int key){
            int hashed_key = hash(key);
            for(auto &it : buckets[hashed_key]){
                if(it->first == key){
                    return i;
                }
            }
            return buckets[hashed_key].end();
        }

        void insert(int key, int val){
            auto it = find(key);
            if(it != buckets[hash(key)].end()){
                it->second = val;
                return;
            }
            buckets[hash(key)].push_back({key,val});
            total_elements++;
            reHashIfNeeded();
        }

        void delete(int key){
            auto it = find(key);
            if(it != buckets[hash(key)].end()){
                buckets[hash(key)].erase(it);
                total_elements--;
            }
        }
};

    
int main() {
    fastio();
    
    return 0;
}