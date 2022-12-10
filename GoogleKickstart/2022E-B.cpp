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

    // taking set of pairs to make sure duplicate values gets reinserted
    set<pair<int,int>>st;
    vector<int>rating(n+1);
    int ans;


    for(int i=0;i<n;i++){
        cin>>rating[i];
        st.insert({rating[i],i+1});
    }
    
    for(int i=0;i<n;i++){
        ans = -1;

        // erasing the current rating as one student cant be the mentor of herself
        st.erase({rating[i],i+1});
        auto itr = st.upper_bound({2*rating[i],INF});

        if(itr != st.begin()){
            itr--;
            ans = itr->first;
        }
        st.insert({rating[i],i+1});
        cout<<ans<<" ";
    }
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