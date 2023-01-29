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
    
 
void solve(){
    int n;
    cin>>n;

    vector<vector<int>>arr(n,vector<int>(n-1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            cin>>arr[i][j];
        }
    }

    unordered_map<int,int>mp;
    mp[arr[0][0]]++; mp[arr[1][0]]++; mp[arr[2][0]]++;

    int x,curr=0;
    for(auto pr : mp){
        if(pr.s>=2){
            x=pr.f;
            break;
        }
        curr = pr.f;
    }

    if(curr==0){
        for(int i=0;i<n;i++){
            if(x!=arr[i][0]){
                curr=arr[i][0];
                break;
            }
        }
    }

    cout<<x<<" ";
    for(int i=1;i<n-1;i++){
        for(int j=0;j<n;j++){
            if(curr != arr[j][i]){
                cout<<curr<<" ";
                curr = arr[j][i];
                break;
            }
        }
    }

    cout<<curr<<" ";
    cout<<"\n";
}
    

int main() {
    fastio();

    int t;
    cin>>t;

    while(t--)
        solve();

    return 0;
}