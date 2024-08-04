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


// Solution1
bool isValid(string temp)
{
    if (temp.length() > 1 && temp[0] == '0')
        return false;

    if (temp.length() > 0 && stoi(temp) > 255)
        return false;

    return true;
}

int counter  = 0;
void rec(string str, vector<string>& ans, int i, int dots)
{
    if (dots == 3)
    {
        string temp = "";
        for (auto ch : str)
        {
            if (ch == '.')
            {  
                // cout << "temp : " << temp << endl;
                if ( !isValid(temp) )
                    return;

                temp = "";
                continue;
            }
            temp.push_back(ch);
        }
        if (isValid(temp))
            ans.push_back(str);

        counter++;
        // cout << str << endl;
        return;
    }

    for (int j = i; j < str.size(); ++j)
    {
        str.insert(j, ".");
        rec(str, ans, j + 2, dots + 1);
        str.erase(j, 1);
    }
}

// Time Complexity = O(3^n * n),  then iterating to find 
// if IP address is valid, Space Complexity = O(1)
vector<string> restoreIpAddresses(string str) {
    if (str.length() > 12)
        return {};

    vector<string> ans; 
    rec(str, ans, 1, 0);

    return ans;
}


// Solution2
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
        if (stoll(num) < 256 and (i == j or num[0] != '0')) // i==j means one digit, so 0 is possible
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

    auto output = restoreIpAddresses("25525511135");
    cout << "output size : " << output.size() << endl;
    cout << "count : " << counter;

    return 0;
}

