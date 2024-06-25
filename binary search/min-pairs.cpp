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

 
/**
 * Given 2 non-empty pairs, find the pair of numbers (a,b) 
 * a->A and b->B array when abs|a-b| is minimum
 */
void minPairs(vector<int>& arr, vector<int>& brr)
{ 
    int a, b;
    int diff = INT_MAX;
    sort(arr.begin(), arr.end());

    for (size_t i = 0; i < brr.size(); ++i)
    {
        int x = brr[i];
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        // left number: < elem
        if (idx >= 1 && x - arr[idx-1] < diff)
        {
            diff = x - arr[idx-1];
            a = arr[idx-1]; b = x;
        }

        // right number or lower_bound idx: >= elem
        if (idx != arr.size() && arr[idx]-x < diff)
        {   
            diff = arr[idx] - x; 
            a = x; b = arr[idx];
        }
    }
    cout << a <<", " << b;
}
    
int main() {
    fastio();

    vector<int> a1{-1, 5, 10, 20, 3};
    vector<int> a2{26, 134, 135, 15, 17};

    minPairs(a1, a2);
    
    return 0;
}