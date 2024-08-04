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



void makeIp(vector<string>& ans, int dots, int i, string& str,
            int len, string ip)
{
    if (dots > 4)
        return;

    if (dots == 4 && i == len)
    {   ip.pop_back();
        ans.emplace_back(ip);
        ip.push_back('.');
        cout << ip << "\n";
        return;
    }

    for (int j = i; j < min(i+3, len); ++j)
    {
        string num = str.substr(i, j-i+1);
        // cout << num << endl;
        if (stoll(num) < 256 and (i == j or num[0] != '0'))
            makeIp(ans, dots+1, j+1, str, len, ip + num + '.');
    }
}

vector<string> restoreIpAddresses(string s) {
    if (s.length() > 12)
        return {};

    vector<string> ans;
    makeIp(ans, 0, 0, s, s.length(), "");

    return ans;
}


int main()
{
    fastio();

    restoreIpAddresses("25525511135");

    return 0;
}

