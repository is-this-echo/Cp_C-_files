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
    int n,m;
    cin>>n>>m;

    vector<int>a(n), b(m), ans;

    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<m;i++)
        cin>>b[i];

    sort(b.begin(),b.end());

    for(int i=0;i<n;i++){
        if(b.empty() || *(b.end()-1)<a[i]){
            cout<<"NO"<<"\n";
            return;
        }

        else if(*(b.end()-1)==a[i]){
            ans.push_back(*(b.end()-1));
            b.erase(b.end()-1);
        }
    }


    if(b.empty()){
        cout<<"NO"<<"\n";
        return;
    }

    ans.push_back(*(b.end()-1));
    b.erase(b.end()-1);
        
    cout<<"YES"<<"\n";
    for(auto i : b)
        cout<<i<<" ";

    for(auto i : ans)
        cout<<i<<" ";

    cout<<"\n";

}
    


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--)
        solve();
    
    return 0;
}