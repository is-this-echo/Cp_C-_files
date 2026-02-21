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
Problem Statement Given a single string which has space separated sorted numbers,
determine whether a specific target number is present in the string.

E.g.
----
Input: "1 23 34 123 453"
Target: 123
Output: true

Solution(s):
------------
1) Brute force approach like, storing these into a list of
    interger and apply binary search. O(logn) time and O(n) space.
2) Apply linear search directly over the string. O(logn) time and O(1) space.

Based on follow up, constraint was that numbers would fit in numeric data type
(So, I ended up coding Binary search)
*/

string findNumAtMid(string &str, int mid)
{
    while (mid >= 0 && str[mid] != ' ') mid--;

    string res;
    mid += 1;

    while(mid < str.size() && str[mid] != ' ')
    {
        res.push_back(str[mid]);
        mid += 1;
    }
    return res;
}

int compareTarget(string &str, string &target, int mid)
{
    string num = findNumAtMid(str, mid);
    if (num.size() > target.size())  // curr num bigger than target, discard 2nd half of string
        return 1;

    if (target.size() > num.size()) // curr num is smaller than target, restrict search to 2nd half
        return -1;

    for (int i = 0; i < target.size(); i++) // both have same length of digits, compare the actual digits now
    {
        if (num[i] > target[i]) // again, curr number is bigger than target, search in 1st half
            return 1;

        else if (num[i] < target[i]) // again, curr number is smaller than target, search in 2nd half
            return -1;
    }
    return 0;
}

bool hasTarget(string &str, string &target)
{
    if(target.size() > str.size())
        return false;

    int start = 0;
    int end = str.size() - 1;

    while(start <= end)
    {
        int mid = start + (end-start) / 2;
        int res = compareTarget(str, target, mid);

        if (res == 0)
            return true;

        else if (res == -1)
            start = mid + 1;

        else
            end = mid - 1;
    }

    return false;
}

int main()
{
    string str = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 1000000000000000000000000000";
    string target = "1000000000000000000000000000";

    cout << "has Target: " <<  std::boolalpha << hasTarget(str, target);

    return 0;
}