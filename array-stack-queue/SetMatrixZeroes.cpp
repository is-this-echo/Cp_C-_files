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
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size(); 
        int firstrow = 5;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]= 0;
                    if(i>0)
                        matrix[i][0]=0;
                    else
                        firstrow=0;
                }
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[0][j]==0 || matrix[i][0]==0)
                    matrix[i][j]=0;
                }
        }
        
        if(matrix[0][0]==0)
            for(int i=0;i<m;i++)
                matrix[i][0]=0;
        
        if(firstrow==0)
            for(int i=0;i<n;i++)
                matrix[0][i]=0;
    }

    void print(vector<vector<int>>&arr){
        for(auto x : arr){
            for(auto y : x)
                cout<<y<<" ";
            cout<<"\n";
        }
        cout<<"\n\n";
    }

};  



int main() {
    fastio();

    Solution st;
    vector<vector<int>>arr={{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    st.print(arr);
    st.setZeroes(arr);
    st.print(arr);

    
    return 0;
}