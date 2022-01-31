#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
const double eps = 1e-12;
    
 // considering a -> shorter side, b-> longer side 
 ll lshapes(ll a, ll b){
     if(a>1 && b>2)
        return min(a,b/2)-1; 
    return 0;
 }


ll solve(){
    int m,n;
    cin>>m>>n;

    vector<vector<int>>grid(m,vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];
    
    int pref_left[m][n],pref_up[m][n], suff_right[m][n], suff_down[m][n];

    // calculating modified prefix and suffix sum matrix 
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int val = grid[i][j];
            int pl = (j>0 ? pref_left[i][j-1] : 0);
            int pu = (i>0 ? pref_up[i-1][j] : 0);

            pref_left[i][j] = (val==1 ? 1+pl : 0);
            pref_up[i][j] = (val==1 ? 1+pu : 0);
        }
    }

    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            int val = grid[i][j];
            int sr = (j<n-1 ? suff_right[i][j+1] : 0);
            int sd = (i<m-1 ? suff_down[i+1][j] : 0);

            suff_right[i][j] = (val==1 ? 1+sr : 0);
            suff_down[i][j] = (val==1 ? 1+sd : 0);
        }
    }

    // computing number of L-shaped plots by making 8 function calls for each (i,j)
    // for each call f(x,y), we are assuming x as the shorter side and y as the longer side
    ll ans=0;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ll a = pref_left[i][j], b = pref_up[i][j], c = suff_right[i][j], d = suff_down[i][j];
            ans += lshapes(b,a)+ lshapes(b,c) + lshapes(a,b) + lshapes(c,b);
            ans += lshapes(d,a) + lshapes(d,c) + lshapes(a,d) + lshapes(c,d);
        }
    }
    return ans;
}
    

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        cout<<"Case #"<<i+1<<": "<<solve()<<"\n";
    }
    
    return 0;
}