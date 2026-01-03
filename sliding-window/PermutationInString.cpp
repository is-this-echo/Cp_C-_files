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
    bool checkInclusion(string s1, string s2)
    {
        vector<int> s1Map(26, 0);
        for (auto ch : s1)
            s1Map[ch - 'a']++;

        int left = 0, right = 0;
        vector<int> s2Map(26, 0);

        while (right < s2.length())
        {
            s2Map[s2[right] - 'a']++;

            if (right - left + 1 == s1.size())
            {
                if (s1Map == s2Map)
                    return true;

                s2Map[s2[left] -'a']--;
                left++;
            }
            right++;
        }
        return false;
    }
};

    
int main() {
    fastio();
    
    return 0;
}