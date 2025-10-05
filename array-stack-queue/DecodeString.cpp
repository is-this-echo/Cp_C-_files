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
    string decodeString(string str)
    {
        std::stack<char> stk;
        for (const auto ch : str)
        {
            if (ch != ']')
            {
                stk.push(ch);
            }
            else
            {
                std::string temp{};
                while (!stk.empty() && stk.top() != '[')
                {
                    temp += stk.top();
                    stk.pop();
                }
                stk.pop();

                std::string multiplierStr{};
                while (!stk.empty() && std::isdigit(stk.top()))
                {
                    multiplierStr = stk.top() + multiplierStr;
                    stk.pop();
                }

                int multiplier = std::stoi(multiplierStr);
                std::ranges::reverse(temp);
                std::string rep{};

                for (int i = 1; i <= multiplier; ++i)
                    rep += temp;

                for (const char cc : rep)
                    stk.push(cc);
            }
        }

        std::string ans{};
        while (!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }

        std::ranges::reverse(ans);
        return ans;
    }
};

    
int main() {
    fastio();
    
    return 0;
}