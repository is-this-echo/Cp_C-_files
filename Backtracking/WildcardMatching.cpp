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
    
 
// using bfs
// time complexity = O(N * 2^k)
// space complexity = O(N * 2^k)
std::vector<std::string> generatePermutations(const std::string& str)
{
    std::vector<std::string> output;
    std::queue<std::string> q;
    q.emplace(str);

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        if (size_t pos = curr.find('?'); pos != std::string::npos)
        {
            curr[pos] = '0';
            q.emplace(curr);

            curr[pos] = '1';
            q.emplace(curr);
        }
        else
        {
            output.emplace_back(curr);
        }
    }
    return output;
}


// using dfs/backtracking
// time complexity = O(N * 2^k)
// space complexity = O(N * 2^k)
void dfs(std::string& str, int idx, std::vector<std::string>& result)
{
    if (idx == str.length())
    {
        result.emplace_back(str);
        return;
    }

    if (str[idx] == '?')
    {
        str[idx] = '0';
        dfs(str, idx + 1, result);

        str[idx] = '1';
        dfs(str, idx + 1, result);

        str[idx] = '?'; // backtrack
    }
    else
    {
        dfs(str, idx + 1, result);
    }
}

std::vector<std::string> generatePermutationsDFS(std::string s)
{
    std::vector<std::string> result;
    dfs(s, 0, result);

    return result;
}


/*
I was asked a variant of the first one in an OA, the question said that there is a string with a wildcard ('?') and it contains only lower-case alphabets. We need to find if by replacing question marks with any of the lowercase alphabets, we can form a palindrome or not.
*/
#include <bits/stdc++.h>
using namespace std;

string shortestPalindrome(string s, const string& charset = "abcdefghijklmnopqrstuvwxyz")
{
    int n = s.size();
    int l = 0, r = n - 1;

    // We'll pick the smallest possible character from the given charset
    char smallest = charset[0];
    while (l <= r)
    {
        if (s[l] == s[r])
        {
            if (s[l] == '?')
            {
                // Replace both '?' with the smallest character
                s[l] = smallest;
                s[r] = smallest;
            }
        }
        else
        {
            // If one is '?' → replace with the other character
            if (s[l] == '?')
                s[l] = s[r];

            else if (s[r] == '?')
                s[r] = s[l];

            else
                return "NO";
                // Conflict: fixed chars differ → impossible
        }
        l++; r--;
    }
    return s;
}


int main()
{
    fastio();

    std::string str{"1??0?"};
    auto ans = generatePermutationsDFS(str);

    for (const auto& s : ans)
        std::cout << s << "\n";
    
    return 0;
}