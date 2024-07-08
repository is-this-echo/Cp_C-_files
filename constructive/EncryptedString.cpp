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

// 3210. Find the Encrypted String
string getEncryptedString(string s, int k) {
    string ans = "";
    int n = s.length();

    for (int i = 0; i < n; ++i)
        ans.push_back(s[(i+k)%n]);

    return ans;
}

 
int main() {
    fastio();

    string str = "dart";
    int k = 3;
    cout << getEncryptedString(str, 3);

    return 0;
}