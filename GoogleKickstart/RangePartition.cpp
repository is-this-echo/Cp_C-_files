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
    
    int n,x,y;
    cin>>n>>x>>y;

    ll sum = (n*n + n)/2;
    float req = x*sum/(float)(x+y);

    if(ceil(req)!=req){
        cout<<"IMPOSSIBLE"<<"\n";
        return;
    }

    vector<int>ans;
    int l=1,r=1;
    sum=0;

    vector<int>arr(n+1);
    for(int i=1;i<=n;i++)
        arr[i]=i;

    while(r<=n){
        sum+= arr[l];
        r++;

        while(sum>req && l<r){
            sum-=arr[l];
            l++;
        }

        if(sum==req){
            for(int i=l;i<r;i++)
                ans.push_back(i);
            break;
        }
    }
    

    int si = ans.size();
    cout<<"POSSIBLE"<<"\n";
    cout<<si<<"\n";

    for(int i=0;i<si;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
}

    
int main() {
    fastio();

    int t;
    cin>>t;

    for(int i=1;i<=t;i++){
        google(i);
        solve();
    }
    
    return 0;
}