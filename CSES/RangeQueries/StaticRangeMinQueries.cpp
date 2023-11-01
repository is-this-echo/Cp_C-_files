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
#define num 200001

double eps = 1e-12;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void google(int t) {cout << "Case #" << t << ": ";}
    
 
 
int arr[num], seg[4*num];

void build(int idx, int low, int high){
    if(low==high){
        seg[idx] = arr[low];
        return;
    }

    int mid = (low+high)>>1;
    build(2*idx+1, low, mid);
    build(2*idx+2, mid+1, high);
    seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
}


int query(int idx, int low, int high, int l, int r){
    if(low>r || high<l)
        return INT_MAX;
    
    if(low>=l && high<=r)
        return seg[idx];
    
    int mid = (low+high)>>1;
    int left = query(2*idx+1, low, mid, l, r);
    int right = query(2*idx+2, mid+1, high, l, r);

    return min(left, right);
}


void solve(){
    int n,q;
    cin >> n >> q; 

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    build(0,0,n-1);

    int a, b;
    while(q--){
        cin >> a >> b;
        a--, b--;

        cout << query(0,0,n-1,a,b) << endl;
    }
    
} 

    
int main() {
    fastio();

    solve();
    
    return 0;
}