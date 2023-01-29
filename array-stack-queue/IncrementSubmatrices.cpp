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
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>matrix(n,vector<int>(n,0));
        
        for(auto v : queries){
            int row1 = v[0]; int col1 = v[1];
            int row2 = v[2]; int col2 = v[3];
            
            for(int i=row1; i<=row2; i++){
                matrix[i][col1] += 1;
                
                if(col2+1<n){
                    matrix[i][col2+1] += -1;
                }
            } 
        }
        
        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                matrix[i][j] += matrix[i][j-1];       
            }     
        }
        return matrix;
    }
};


int main() {
    fastio();

    vector<vector<int>>queries = {{1,1,2,2},{0,0,1,1}};
    int n=3;

    Solution sl;
    auto grid = sl.rangeAddQueries(3,queries);

    for(auto x : grid){
        for(auto y : x ){
            cout<<y<<" ";
        }
        cout<<'\n';
    }

    return 0;
}