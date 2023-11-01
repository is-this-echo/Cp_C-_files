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
    cin >> n;

    vector<int>k(n);
    for(int i=0; i<n; i++){
        cin >> k[i];
    }

    unordered_map<int,int>mp;
    int l=0, r=0;
    int ans = INT_MIN;

    while(r<n-1){
        mp[k[r]]++;

        if(mp[k[r]]>1){
            ans = max(ans, r-l);

            while(mp[k[r]]>1){
                mp[k[l]]--;
                l++;
            }
        }
        r++;
    }

    if(mp.count(k[r]) == 0)
        ans = max(ans, r-l+1);
    
    else
        ans = max(ans, r-l);
    
    cout << ans << endl;
}


void solve2(){
    int n;
    cin >> n;

    vector<int>k(n);
    for(int i=0; i<n; i++){
        cin >> k[i];
    }

    set<int>st;
    int l=0, ans=0;
    for(int i=0; i<n; i++){
        // if exists in set, contract window
        while(st.count(k[i])){
            st.erase(k[l]);
            l++;
        }

        // insert new number in set
        st.insert(k[i]);
        ans = max(ans, (int)st.size());
    }

    cout << ans << endl;

}

    
int main() {
    fastio();

    solve2();
    
    return 0;
}