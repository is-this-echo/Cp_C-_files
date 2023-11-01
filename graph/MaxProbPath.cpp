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
public:
 double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        list<pair<double,int>>l[n+1];

        for(int i=0; i<edges.size(); i++){
            l[edges[i][0]].push_back({succProb[i],edges[i][1]});
            l[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }

        // auto compare = [](const pair<double,int>&x, const pair<double,int>&y) {
        //                         return x.first - y.first > 1e-12; };

        vector<double>dist(n,-1.0);
        // vector<bool>vis(n,false);
        set<pair<double,int>,greater<pair<double,int>>>st;
        // set<pair<double,int>,decltype(compare)> st;

        dist[start] = 1.0;
        st.insert({dist[start],start});

        while(!st.empty()){
            auto itr = st.begin();
            double probTillNow = itr->first;
            int node = itr->second;

            st.erase(itr);

            for(auto nbrPair : l[node]){
                double currEdge = nbrPair.first;
                int nbr = nbrPair.second;

                if(probTillNow * currEdge > dist[nbr]){
                    auto elem = st.find({dist[nbr],nbr});

                    if(elem!=st.end())
                        st.erase(elem);

                    dist[nbr] = 1.0 * probTillNow * currEdge; 
                    st.insert({dist[nbr],nbr});
                }
            }
        }

        if(dist[end] == -1)
            return 0;
        
        return dist[end];
    }
};


int main() {
    fastio();
    
    return 0;
}