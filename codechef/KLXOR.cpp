#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
 


void solve2(){
    int n,k;
    cin>>n>>k;

    string s,t;
    cin>>s;

    vector<ll>arr(n,0);
    ll ans=0,cnt=0;

    for (int i=0; i<n; i++){
        if(s[i]=='1')
            ans++;

        arr[i]=ans;
    }

    vector<int>num(k);
    int e = n-k+1;
    num[0] = arr[e-1];

    for (int i=1; i<k; i++)
        num[i] = arr[i+e-1]-arr[i-1];
    

    for (int i=0; i<k; i++)
        if(num[i]%2==1) 
            cnt++;

    cout<<cnt<<"\n";

}


void solve(){
    int n,k;
    cin>>n>>k;

    string s,t;
    cin>>s;

    ll cnt=0,ans=0,num;
    for(int i=0;i<=n-k;i++){
        t = s.substr(i,k);
        num = stoi(t);
        //cout<<num<<" ";
        ans = ans^num;
    }
    //cout<<ans<<"  ";
    t = to_string(ans);

    for(auto ch : t){
        if(ch=='1')
            cnt++;
    }
  
    cout<<cnt<<"\n";
}


    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--)
        solve2();
    
    return 0;
}