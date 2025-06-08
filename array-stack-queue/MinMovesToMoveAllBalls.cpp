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
  
// O(n^2) solution
class Solution {
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.length();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; ++i)
        {
            // check left boxes
            int j = i - 1;
            while (j >= 0)
            {
                ans[i] += (boxes[j] == '1') ? (i - j) : 0;
                j--;
            }
,
            // check right boxes
            j = i + 1;
            while (j < n)
            {
                ans[i] += (boxes[j] == '1') ? (j - i) : 0;
                j++;
            }
        }
        return ans;
    }
};


// O(n^2) solution
class Solution {
public:
    vector<int> minOperations(string boxes)
    {   
        int n = boxes.length();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ans[i] += (boxes[j] == '1') ? abs(j - i) : 0;
        return ans;
    }
};

// O(n) solution
class Solution {
public:
    vector<int> minOperations(string boxes)
    {   
        int n = boxes.length();
        int balls = 0, moves = 0;
        vector<int> ans(n, 0);

        // moves required to shift from left to right
        for (int i = 0; i < n; ++i)
        {
            ans[i] = (moves + balls);
            moves = ans[i];

            if (boxes[i] == '1')
                balls++;
        }

        balls = 0, moves = 0;
        // moves required to shift from right to left
        for (int i = n - 1; i >= 0; --i)
        {
            ans[i] += (moves + balls);
            moves = (moves + balls);

            if (boxes[i] == '1')
                balls++;
        }

        return ans;
    }
};


int main() {
    fastio();
    
    return 0;
}