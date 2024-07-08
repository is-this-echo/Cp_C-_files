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



int countSubsets(const vector<int>& arr, int i, const int n, int sum)
{
    if (i == n)
    {
        if (sum == 0) 
            return 1;
        else
            return 0;
    }

    int inc = countSubsets(arr, i+1, n, sum - arr[i]); // include ith number in the sum
    int exc = countSubsets(arr, i+1, n, sum); // do not include ith number in the sum
    return inc + exc;
}


int countSubsets2(const vector<int>& arr, int n, int sum)
{
    if (n < 0)
    {
        if (sum == 0) return 1;
        return 0;
    }

    return countSubsets2(arr, n-1, sum - arr[n]) + countSubsets2(arr, n-1, sum);
}


int main() {
    fastio();

    vector<int> arr{1,2,3,4,5};
    int sum = 6;

    cout << countSubsets(arr, 0, arr.size(), sum) << endl;
    cout << countSubsets2(arr, arr.size()-1, sum) << endl;

    return 0;
}