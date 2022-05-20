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
    
 
// O(n^2) time complexity

void Z_algo_trivial(string s){
    int n = (int) s.length();
    vector<int>z(n,0);

    for(int i=1;i<n;i++){
        while(i+z[i]<n && s[z[i]]==s[i+z[i]])
            ++z[i];
    }

    for(auto i : z)
        cout<<i<<" ";
    cout<<"\n";
}



//  O(n) time complexity

void Z_algo(string s){
    int n = (int) s.length();
    vector<int> z(n);
    int l=0,r=0;

    for (int i = 1; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]); 

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];

        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    
    for(auto i : z)
        cout<<i<<" ";
    cout<<"\n";

}

    
int main() {
    fastio();

    // src = pattern + "#" + text
    string txt = "aba#aababac";

    Z_algo(txt);
    
    return 0;
}