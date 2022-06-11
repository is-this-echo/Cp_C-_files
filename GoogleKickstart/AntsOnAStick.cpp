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
    int n,l;
    cin>>n>>l;

    vector<int>p(n+1);
    vector<int>d(n+1);
    vector<pair<int,int>>pos(n+1);
    vector<pair<int,int>>fall(n+1);

    for(int i=1;i<=n;i++){
        cin>>p[i]>>d[i];
    }

    for(int i=1;i<=n;i++){
        pos[i]={p[i],i};

        if(d[i]==0)
            fall[i] = {p[i],i};
        
        else
            fall[i] = {l-p[i],i};
    }

    sort(pos.begin(),pos.end());
    sort(fall.begin(),fall.end());

    int le=1,r=n;
    vector<int>ans;

    for(int k=1;k<=n;k++){  
        int m = k+1;

        while(m<=n && fall[k].f==fall[m].f){
            m++;
        }

        m-=1;
        vector<int>temp;

        for(int i=k;i<=m;i++){
            if(d[fall[i].s]){
                temp.push_back(pos[r].s);
                r--;
            }
            else{
                temp.push_back(pos[le].s);
                le++;
            }
        }
        // as we have a k++ in the for loop, which shifts k to the next element
        k = m;
        sort(temp.begin(),temp.end());
        for(auto x : temp) ans.push_back(x);
    }

    for(auto x : ans) cout<<x<<" ";
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