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


class Solution
{
public:
    bool validWordAbbreviation(string word, string abbr)
    {
        int m = word.size(), n = abbr.size();
        int i = 0, j = 0, x = 0;

        for (; i < m && j < n; ++j)
        {
            if (isdigit(abbr[j]))
            {
                if (abbr[j] == '0' && x == 0)
                    return false;

                x = x * 10 + (abbr[j] - '0');
            }
            else
            {
                i += x;
                x = 0;

                if (i >= m || word[i] != abbr[j])
                    return false;

                ++i;
            }
        }
        return i + x == m && j == n;
    }
};


int main() {
    fastio();

    Input: word = "internationalization", abbr = "i12iz4n"
    Output: true
    
    return 0;
}