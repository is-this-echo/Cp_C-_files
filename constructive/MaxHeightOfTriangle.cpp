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
    
 // 3200. Maximum Height of a Triangle
int findRows(int first, int second)
{
    int row = 1;
    while (1)
    {
        if (first == 0 && second == 0)
            break;

        if (row & 1)
        {
            first -= row;
            if (first < 0) break;
        }
        else
        {
            second -= row;
            if (second < 0) break;
        }
        row++;
    }
    return row-1;
}

int maxHeightOfTriangle(int red, int blue) {
    int ans = 0;

    // taking first color as red
    ans = max(ans, findRows(red, blue));
    // taking first color as blue
    ans = max(ans, findRows(blue, red));

    return ans;        
}

int main() {
    fastio();
    
    return 0;
}