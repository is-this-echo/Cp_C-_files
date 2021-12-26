#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;

/* input  
4
3
3 3 3
4
1 2 1 2
5
1 2 3 2 1
8
1 2 2 3 2 3 3 1

output
3
10
16
54
*/

void solve(){
    int n;
    cin>>n;

    // if the array size is n, then we can have the maximum element that contributes
    // to the answer is n, as n+1 must have n+1 occurences.

    // storing indices of occurence of every number from 1 to n
    vector<vector<int>> indices(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;

        if(x<=n)
            indices[x].push_back(i);
    }
    
    ll ans=0;
    // iterate from 1 to n, take their indices and find number of subarrays in which they will
    // contribute to the ans
    for(int x=1;x<=n;x++){
        vector<int>indsx = indices[x];

        // padding at the start and the end to handle edge cases error like when one 
        // element is at the nth index
        indsx.insert(indsx.begin(),0);
        indsx.push_back(n+1);

        // computing the number of subarrays, since a number x should have atleast x occurences
        // the size of indsx after padding must be min. x+2 for the for(i) loop to run atleast
        // once, i denotes starting indices
        for(int i=1;i<(int)indsx.size()-x;i++){
            ans+= (ll)x * (indsx[i]-indsx[i-1]) * (indsx[i+x]-indsx[i+x-1]);
        }
    }
    cout<<ans<<"\n";
}


    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}