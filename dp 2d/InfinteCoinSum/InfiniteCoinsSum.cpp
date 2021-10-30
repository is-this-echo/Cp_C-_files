
/*You are given a set of coins S. 
In how many ways can you make sum N assuming you have infinite amount of each coin in the set.
Note : Coins in set S will be unique. Expected space complexity of this problem is O(N).
Example :
Input : 
	S = [1, 2, 3] 
	N = 4
Return : 4
Explanation : The 4 possible ways are
{1, 1, 1, 1}
{1, 1, 2}
{2, 2}
{1, 3}	
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

const long mod = 1e6+7;
vector<vector<int>>dp;

// 1) solution using tabulation
int count(int m, vector<int> &coins){
    int ncoins = coins.size();
    vector<vector<int>> dp(ncoins+1,vector<int>(m+1,0));

// base cases
    for(int i=0;i<=ncoins;i++)
        dp[i][0]=1;

    for(int j=1;j<=m;j++)
        dp[0][j]=0;
    

    for(int i=1;i<=ncoins;i++){
        for(int j=1;j<=m;j++){
            if(j-coins[i-1]>=0)
                dp[i][j] = dp[i-1][j]%mod + dp[i][j-coins[i-1]]%mod;
            else
                dp[i][j] = dp[i-1][j]%mod;
        }
    }
    return dp[ncoins][m]%mod;
}


// 2) solution approach using recursion
int coinChange(vector<int>& coins, int n, int amount)
{
    if(amount == 0)
        return 1;
        
    if(n==0)
        return 0;
    
    if(coins[n-1] > amount)
        return coinChange(coins, n-1, amount);

    return coinChange(coins, n, amount-coins[n-1]) + coinChange(coins, n-1, amount);
}


int change(int amount, vector<int>& coins) {
    int n = coins.size();
    if(amount == 0) {
        return 1;
    }
    if(n==0)
        return 0;

    return coinChange(coins, n, amount);
}



// 3) solution using dp memoization
int coinChangeDP(vector<int>& coins, int n, int amount)
{
    if(amount == 0)
        return 1;

    if(n==0)
        return 0;
    
    if(dp[n][amount] != -1)
        return dp[n][amount];
    
    if(coins[n-1] > amount)
    {
        dp[n][amount] = coinChangeDP(coins, n-1, amount);
        return dp[n][amount];
    }
    // unbounded knapsack type
    dp[n][amount] = coinChangeDP(coins, n, amount-coins[n-1]) + coinChangeDP(coins, n-1, amount);

    return dp[n][amount];
}


int changeDP(int amount, vector<int>& coins) {
    int n = coins.size();
    // if(amount == 0) 
    //     return 1;
    
    // if(n==0)
    //     return 0;
    
    dp.resize(n+1,vector<int>(amount+1,-1));
    dp[n][amount] = coinChangeDP(coins, n, amount);

    return dp[n][amount];
}




int main()
{   
    vector<int> denoms = {18, 24, 23, 10, 16, 19, 2, 9, 5, 12, 17, 3, 28, 29, 4, 13, 15, 8};
    int m=458,m2=5;
    vector<int> denoms2{1,2,5};

    cout<<count(m,denoms)<<endl;
    cout<<change(m2,denoms2)<<endl;
    cout<<changeDP(m2,denoms2);

    return 0;
}