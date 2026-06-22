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


/*
Q1)
You are given a string consisting of lowercase English letters and # characters.
A # acts as a blocker, meaning a safe path cannot cross it.
Find the longest safe path, where a safe path is defined as the longest continuous substring containing only lowercase letters and no #.
If multiple substrings have the same maximum length, return any one of them.

Input: ab#cdef##gh
Output: cdef

TC: O(N) , SC: O(1)
*/
 
std::string safeCount(const std::string& str)
{
    int count = 0, maxCount = 0;
    int startIdx = 0, maxStartIdx = 0;

    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '#')
        {
            if (count > maxCount)
            {
                maxCount = count;
                maxStartIdx = startIdx;
            }

            startIdx = i + 1;
            count = 0;
        }
        else
        {
            count++;
        }
    }

    if (count > maxCount)
    {
        maxCount = count;
        maxStartIdx = startIdx;
    }

    return str.substr(maxStartIdx, maxCount);
}


/*
Q2)
Follow up: What if we allow one hash to be considered safe.
input: ab##cde#fghij so segment [2,0,3,5]

Solution: Sliding window by keeping 1 # in substring
TC: O(N) , SC: O(1)
*/

string safeCountWithOneHash(const std::string& str)
{
    int left = 0, startIdx = 0;
    int maxLen = 0;
    int hashCount = 0;

    for (int right = 0; right < str.length(); ++right)
    {
        if (str[right] == '#')
            hashCount++;

        while (hashCount > 1)
        {
            if (str[left] == '#')
                hashCount--;

            ++left;
        }

        int currLen = right - left + 1;
        if (currLen > maxLen)
        {
            maxLen = currLen;
            startIdx = left;
        }
    }

    return str.substr(startIdx, maxLen);
}


int main()  
{
    fastio();

    cout << safeCount("ab#cdef##gh") << std::endl;
    cout << safeCountWithOneHash("ab#cdef##gh") << std::endl;
    cout << safeCount("abcdefgh") << std::endl;

    return 0;
}  

