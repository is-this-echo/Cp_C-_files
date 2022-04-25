
/*
Leetcode
338. Counting Bits -> number of set bits from 0 to n
*/

#include<iostream>
#include<vector>
using namespace std;


#define ll long long
#define mod 998244353
double eps = 1e-12;
    

// (n & n-1) removes the last set bit in n, TC = O(nlogn)
vector<int> countBits(int n) {  
    vector<int>out(n+1);
    
    for(int i=0;i<=n;i++){
        int x=i,ans=0;
        while(x>0){
            x=x&(x-1);
            ans++;
        }
        // out.push_back(ans);
        out[i]=ans;
    }
    return out;
}


// dp soln, check neetcode if approach not clear, TC = O(n)
vector<int> countBits(int n) {  
    vector<int>dp(n+1);

    dp[0]=0;
    int setbit = 1;

    for(int i=1;i<=n;i++){
        if(setbit*2==i)
            setbit=i;
        dp[i] = 1 + dp[i-setbit];
    }
    return dp;
        
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n=10;
    vector<int>ans = countBits(n);

    for(auto x : ans)
        cout<<x<<" ";

    return 0;
}