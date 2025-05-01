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



// Solution-1 using string modification, not a good idea
class Solution {
    bool isPalindrome(string& str)
    {
        int l = 0, r = str.length() - 1;
        while (l < r)
        {
            if (str[l] != str[r])
                return false;

            l++, r--;
        }
        return true;
    }

    void helper(string s, vector<string>& temp, vector<vector<string>>& ans)
    {
        if (s.length() == 0)
        {
            ans.emplace_back(temp);
            return;
        }

        for (int i = 0; i < (int)s.length(); ++i)
        {
            string part = s.substr(0, i + 1);
            if (isPalindrome(part))
            {
                temp.emplace_back(part);
                helper(s.substr(i+1), temp, ans);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> temp;
    
        helper(s, temp, ans);
        return ans;
    }
};

// Solution-2 using index tracker without string modification
class Solution {

    bool isPalindrome(string& str)
    {
        int l = 0, r = str.length() - 1;
        while (l < r)
        {
            if (str[l] != str[r])
                return false;

            l++, r--;
        }
        return true;
    }

    void helper(int idx, string s, vector<string>& temp, vector<vector<string>>& ans)
    {
        if (idx == s.length())
        {
            ans.emplace_back(temp);
            return;
        }

        for (int i = idx; i < (int)s.length(); ++i)
        {
            // increment partition window by 1, so not s.substr(idx, i + 1)
            string part = s.substr(idx, i - idx + 1);
            if (isPalindrome(part))
            {
                temp.emplace_back(part);
                helper(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> temp;
    
        helper(0, s, temp, ans);
        return ans;
    }
};
    

int main() {
    fastio();
    
    return 0;
}
