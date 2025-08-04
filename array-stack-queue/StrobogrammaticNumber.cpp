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
    
 
// OJ: https://leetcode.com/problems/strobogrammatic-number/
// Time: O(N)
// Space: O(1)
class Solution
{
private:
    bool same(char a, char b) {
        return a == b && (a == '0' || a == '1' || a == '8');
    }
    bool match(char a, char b) {
        if (a > b) swap(a, b);
        return same(a, b) || (a == '6' && b == '9');
    }
public:
    bool isStrobogrammatic(string num) {
        int i = 0, j = num.size() - 1;
        for (; i <= j; ++i, --j) {
            if ((i != j && !match(num[i], num[j]))
               || (i == j && !same(num[i], num[j]))) return false;
        }
        return true;
    }
};


int main() {
    fastio();
    
    return 0;
}