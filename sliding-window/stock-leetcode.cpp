#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
const double eps = 1e-12;
    
 
  int maxProfit(vector<int>& prices) {
    // sliding window approach
        int l=0, r=1;
        int maxProfit = 0;

        while(r < prices.size()){
            if(prices[l] < prices[r])
                maxProfit = max(maxProfit, prices[r]-prices[l]);
            
            else 
                l = r;
            
            r++;
        }
    return maxProfit;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<int>prices = {7,1,5,3,6,4};

    cout<<maxProfit(prices);


    return 0;
}