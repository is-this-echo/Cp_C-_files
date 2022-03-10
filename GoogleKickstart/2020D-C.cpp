#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
 
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int ts;
    cin>>ts;

    for(int tt=0;tt<ts;tt++){
        int n;
        cin>>n;

        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        list<int>l[n];
        for(int i=0;i<n;i++){
            l[arr[i]].push_back(i+2);
        }

        queue<list<int>>q;

    }
    
    return 0;
}