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



class Node{
public:
    int val;
    Node *left, *right;

    Node(int val) : val(val), left(NULL), right(NULL) {}
};


void solve(){
    int arr[] = {5,1,0,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<vector<int>>subarrays;
    vector<int>temp;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            temp.push_back(arr[j]);
            subarrays.push_back(temp);
        }
        temp.clear();
    }

    for(auto x : subarrays){
        for(auto y : x)
            cout << y <<",";
        cout << "\n";
    }

}

int main()
{
    fastio();
    solve();

    return 0;
}

