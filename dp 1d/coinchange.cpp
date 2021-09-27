#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// bottom up approach, iterative solution
int minCoinsBU(int m, vector<int> &denoms){

    vector<int> dp(m+1,0);
    dp[0]=0;

    for(int i=1;i<=m;i++){
        dp[i] = INT_MAX;
        for(int coin : denoms){
            if(i-coin>=0 && dp[i-coin]!=INT_MAX){
                dp[i] = min(dp[i],dp[i-coin]+1);
            }
        }
    }
    return dp[m]==INT_MAX?-1:dp[m];
}


//Top down approach using recursion
int minCoinsTD(int m, vector<int> &denoms, vector<int> &dp){

    if(m==0)
        return 0;
    
    if(dp[m]!=0)
        return dp[m];

        dp[m]=INT_MAX;

        for(auto coin : denoms){
            if(m-coin>=0 && dp[m-coin]!=INT_MAX){
                int subProb = minCoinsTD(m-coin,denoms,dp)+1;
                 if(subProb!=INT_MAX)
                    dp[m] = min(dp[m],subProb);
            }
               
        }
        return dp[m]==INT_MAX?-1:dp[m];
}


int main()
{
    int m=18;
    vector<int> coins = {5,7,10};
    vector<int> dp(m+1,0);

    cout<<"Min. coins required: "<<minCoinsBU(m,coins)<<endl;
    cout<<"Min. coins required: "<<minCoinsTD(m,coins,dp)<<endl;
    
    return 0;
}