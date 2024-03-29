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



void solve() {

    set<int>st;
    st.insert(2);
    st.insert(3);
    st.insert(9);
    st.insert(1);

    for(auto x : st){
        cout << x << " ";
    }
    cout << endl;

    st.erase(8);

    for(auto x : st)
        cout << x << " ";
    cout << endl;
}



int main() {
    fastio();

    solve();

    return 0;
}