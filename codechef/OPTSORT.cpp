#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
 

void solve(){
    int n,val,ans=0;
    cin>>n;

    vector<int>arr(n),ideal(n);

    for(int i=0;i<n;i++){
        cin>>val;

        arr[i]=val;
        ideal[i]=val;
    }
        
    sort(ideal.begin(),ideal.end());
    multiset<int>p,q;

    for(int i=0;i<n;i++){
        p.insert(arr[i]);
        q.insert(ideal[i]);

        if(p==q){
            ans += (*(p.rbegin()) - *p.begin());
            p.clear();
            q.clear();
        }
    }
    cout<<ans<<"\n";

}
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--)
        solve();
    
    return 0;
}