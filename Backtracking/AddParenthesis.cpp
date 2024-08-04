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
  

vector<int> helper(string str)
{
    // This also works if there is only at max 2-digit numbers in the expression
    if (str.length() <= 2)
        return {stoi(str)};

    vector<int> ans;
    for (int i = 0; i < str.length(); ++i)
    {
        char ch = str[i];
        if (ch == '+' or ch == '-' or ch == '*')
        {
            vector<int> left = helper(str.substr(0, i));
            vector<int> right= helper(str.substr(i+1));

            for (auto l : left)
            {
                for (auto r : right)
                {
                    switch (ch)
                    {
                        case '+' :  ans.emplace_back(l + r);
                                    break;

                        case '-' :  ans.emplace_back(l - r);
                                    break;

                        case '*' :  ans.emplace_back(l * r);
                                    break;
                    }
                }
            }
        }
    }

    // This works for any digit number in the expression, more generic and accepted solution
    // if (ans.size() == 0)
    //     return {stoi(str)};
    return ans;
}


vector<int> diffWaysToCompute(string expression) {

    return helper(expression);
}



int main()
{
    fastio();

    auto ans = diffWaysToCompute("2*3-4*5");

    for (auto x : ans)
        cout << x << endl;

    return 0;
}

  
int main() {
    fastio();
    
    return 0;
}