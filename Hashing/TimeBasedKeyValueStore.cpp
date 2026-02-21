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


class TimeMap
{
public:
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        hashMap[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp)
    {
        const auto& vec = hashMap[key];

        int left = 0;
        int right = vec.size() - 1;
        string ans;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (vec[mid].first == timestamp)
            {
                return vec[mid].second;
            }
            else if (vec[mid].first < timestamp)
            {
                ans = vec[mid].second;
                left = mid + 1;              
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }

private:
    map<string,vector<pair<int,string>>> hashMap;
};


int main()
{
    fastio();
    
    return 0;
}