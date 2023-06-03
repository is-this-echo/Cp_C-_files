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
    
 
class Solution {
const int modd = (int)1e9 + 7;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>eng;
        for(int i=0; i<n; i++){
            eng.push_back(make_pair(efficiency[i],speed[i]));
        }

        sort(eng.begin(), eng.end(), [&](const pair<int,int>a, pair<int,int>b){
            return a.f >= b.f;
        });

        priority_queue<int, vector<int>, greater<int>>pq;
        ll ts = 0, eff = 0, ans = 0;

        for(int i=0;i<n;i++){
            if(pq.size()==k){
                ts -= pq.top();
                pq.pop();
            }

            eff = eng[i].f;
            ts += eng[i].s;
            pq.push(eng[i].s);

            ans = max(ans, ts*eff);
        }
        return ans % modd;
    }
};
    
int main() {
    fastio();

    Solution st;
    vector<int>speed{2,10,3,1,5,8}, efficiency{5,4,3,9,7,2};
    int n = 6, k = 3;

    cout<<st.maxPerformance(n,speed,efficiency,k);

    return 0;
}