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

int cnt = 0 ;

void permute(string str, int l, int r){
    if(l==r){
        cnt++;
        cout<<str<<endl;
        return;
    }

    for(int i=l; i<=r; i++){
        swap(str[i], str[l]);
        permute(str,l+1,r);
        swap(str[i], str[l]);
    }
}

int main() {
    fastio();

    string str = "abc";
    permute(str, 0, str.length()-1);

    cout << cnt;

    return 0;
}