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
    
 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n= a.size();
        vector<int> prefixProd(n+1,1);
        vector<int> suffixProd(n+1,1);
        vector<int> ans(n,1);

        for(int i=1;i<=n;i++)
            prefixProd[i]= a[i-1] * prefixProd[i-1];

        for(int i=n-1;i>=0;i--)
            suffixProd[i] = a[i]*suffixProd[i+1];

        for(int i=0;i<n;i++)
            ans[i] = prefixProd[i]*suffixProd[i+1];

        return ans;
    }
};


int main() {
    fastio();
    
    return 0;
}