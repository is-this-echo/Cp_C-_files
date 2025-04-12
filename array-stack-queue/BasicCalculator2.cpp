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


// 227. Basic Calculator II
/*
    The issue in this question is with the * and division operations as they have higher 
    precedence and we need to have knowledge of 2 numbers behind, for ex-> 3 + 2 * 2,
    if we iterate normally over the string then we can't just do the addition when we get
    the first '+' operator as we don't know if the 2nd operand(one the right) will be 
    involved in multiplication or division. So, we store the current operator to be used
    in next iteration and also by ease the calculations by defaulting the stack operation
    to be addition and store subtraction with a (- * currentNumber) in stack.

*/
class Solution {
    bool isOperator(char ch)
    {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }

public:
    int calculate(string s) {
        int len = s.length();
        stack<int> stk;

        if (len == 0) return 0;

        int currNum = 0, num;
        char currOperation = '+'; // default operation
        for (int i = 0; i < len;  ++i)
        {
            char currCh = s[i];
            if (std::isdigit(currCh))
                currNum = currNum * 10 + (currCh - '0');

            if (isOperator(currCh) || i == len - 1)
            {
                switch (currOperation)
                {
                    case '+' : 
                        stk.push(currNum);
                        break;
                    case '-' : 
                        stk.push(-1 * currNum);
                        break;
                    case '*' :
                        num = stk.top();
                        stk.pop();
                        stk.push(num * currNum);
                        break;
                    case '/' :
                        num = stk.top();
                        stk.pop();
                        stk.push(num / currNum);
                        break;
                }
                currOperation = currCh;
                currNum = 0;
            }
        }

        int result = 0;
        while (!stk.empty())
        {
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};


int main() {
    fastio();
    
    return 0;
}