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
const int num = 200001;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void google(int t) {cout << "Case #" << t << ": ";}
    

ll arr[num], seg[4*num];

void build(int idx, int low, int high){
    if(low==high){
        seg[idx] = arr[low];
        return;
    }

    int mid = (low+high)>>1;
    build(2*idx+1, low, mid);
    build(2*idx+2, mid+1, high);
    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}


void pointUpdate(int idx, int low, int high, int node, int val){
    if(low==high){
        seg[idx] = val;
        // cout << "changes at idx "<< low << " to "<< arr[low] << endl;
        return;
    }

    int mid = (low+high)>>1;
    if(low<=node && node<=mid)
        pointUpdate(2*idx+1, low, mid, node, val);
    
    else
        pointUpdate(2*idx+2, mid+1, high, node, val);
    
    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}


ll query(int idx, int low, int high, int l, int r){
    if(low>r || high<l)
        return 0;
    
    if(low>=l && high<=r)
        return seg[idx];
    
    int mid = (low+high)>>1;
    ll left = query(2*idx+1, low, mid, l, r);
    ll right = query(2*idx+2, mid+1, high, l, r);

    return left + right;
}


void solve(){
    int n,q;
    cin >> n >> q;

    for(int i=0; i<n; i++)
        cin >> arr[i];

    build(0,0,n-1);

    int t, x, y;
    while(q--){
        cin >> t >> x >> y;

        if(t==1){
            x--;
            pointUpdate(0,0,n-1,x,y);
        }
        
        else{
            x--, y--;
            cout << query(0,0,n-1,x,y) << endl;
        }
    }
}

    
int main() {
    fastio();

    solve();
    
    return 0;
}