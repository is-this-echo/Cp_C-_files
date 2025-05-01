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
void meta(int t) {cout << "Case #" << t << ": ";}


struct Node
{
    int val;
    Node *left, *right;

    Node(int d) : val(d), left(NULL), right(NULL) {}
};





void print(vector<int>& arr)
{
    for (int i : arr)
        std::cout << i << " ";

    std::cout << std::endl;
}


int main()  
{
    fastio();

    int n = 5, k = 3;

    vector<int> dp(n+1, 0);
    cout << countWays(n, k, dp) << endl;
    cout << countWaysBU(n, k) << endl;
    

    return 0;
}  

