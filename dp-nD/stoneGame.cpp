// leetcode 877

#include<iostream>
#include<vector>
using namespace std;


int dfs(vector<vector<int>>&dp,  vector<int> &piles, int l, int r){
    if(l>r)
        return 0;
    
    if(dp[l][r]!=0)
        return dp[l][r];

    int left = (r-l)%2!=0 ? piles[l] : 0;
    int right = (r-l)%2!=0 ? piles[r] : 0;

    int op1 = left + dfs(dp,piles,l+1,r);
    int op2 = right + dfs(dp,piles,l,r-1);

    return dp[l][r] =  max(op1,op2);
}



int stoneGame(vector<int>& piles) {
    int n = piles.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    int l = 0, r=n-1;
    int out = dfs(dp,piles,l,r);

    for(auto rows: dp){
        for(auto cols : rows)
            cout<<cols<<" ";
        cout<<endl;
    }
    return out;
}



int main()
{
    vector<int> piles = {5,4,8,10};
    int sum=0,ans;

    ans = stoneGame(piles);
    cout<<ans<<endl;
    
    for(auto x: piles)
        sum+=x;

    bool canWin = ans>sum/2 ? true : false;
    cout<<canWin;

    return 0;
}