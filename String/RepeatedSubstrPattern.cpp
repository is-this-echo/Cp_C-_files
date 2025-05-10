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
    bool repeatedSubstringPattern(string s)
    {
        int n = s.length();
        for (int i = 1; i <= n/2; ++i)
        {
            if (n % i == 0)
            {
                string sub = s.substr(0, i);
                string temp = "";

                for (int len = i; len <= n; len += i)
                    temp += sub;
                
                if (temp == s)
                    return true;
            }

        }
        return false;
    }
};


int main() {
    fastio();
    
    return 0;
}