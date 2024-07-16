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


// 1823. Find the Winner of the Circular Game

/* Using deque
 * TimeComplexity = O(n*k), SpaceComplexity = O(n)
 */
int findTheWinner(int n, int k) {
    deque<int>dq;
    for (int i = 1; i <= n; i++)
        dq.push_back(i);

    // TC = O(n)
    while (dq.size() >  1)
    {   
        // TC = O(k)
        // pop from front and append at back the first k-1 elements
        for (int i = 1; i < k; ++i)
        {
            int val = dq.front();
            dq.pop_front();
            dq.push_back(val);
        }
        // pop the kth element from front to remove it from game
        dq.pop_front();
    }
    return dq.front();
}
    
int main() {
    fastio();
    
    return 0;
}