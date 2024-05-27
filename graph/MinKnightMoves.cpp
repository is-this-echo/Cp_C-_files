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
    

int minimumKnightMoves(int x, int y) {
    int dx[] = {1,1,2,2,-1,-1,-2,-2};
    int dy[] = {2,-2,1,-1,2,-2,1,-1};

    queue<pair<int,int>>q;
    q.push({0,0});

    int ans = 1;
    set<pair<int,int>>st;
    st.insert({0,0});
    
    while(!q.empty()){
        int len = q.size();

        for(int i=0; i<len; i++){
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            for(int k=0; k<8; k++){
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                
                if(nx==x && ny==y)
                    return ans;

                if(st.find({nx,ny}) != st.end())
                    continue; 
                
                st.insert({nx,ny});
                q.push({nx,ny});
            }

        }
        ans++;
    }

    return ans;
}