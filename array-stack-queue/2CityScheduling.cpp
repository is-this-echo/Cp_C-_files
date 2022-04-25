/* Debjyoti Ghosh*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void google(int t) {cout << "Case #" << t << ": ";}
    

 // greedy approach, TC = O(nlogn)
 // dp approach, TC = O(n*n)
 

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        multimap<int,int>mp;
        int n = costs.size();
        
        for(int i=0;i<n;i++){
            
            int a = costs[i][0];
            int b = costs[i][1];
            
            mp.insert({(b-a),i});
        }
        
        int count=0;
        long ans=0;
        
        for(auto x : mp){
            if(count<n/2)
                ans += costs[x.second][1];
            
            else
                ans += costs[x.second][0];
            
            count++;
        }
        
        return ans;
    }
};
    

int main() {
    fastio();

    vector<vector<int>>costs = {{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}};

    Solution st;
    cout<<st.twoCitySchedCost(costs);
    
    return 0;
}