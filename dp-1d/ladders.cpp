#include<iostream>
#include<vector>
using namespace std;


// bottom up approach using DP
int ladderBU(int n, int k){
    int dp[100]={0};
    dp[0]=1;

    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=i-k && j>=0;j--)
            dp[i]+=dp[j];
    }
    return dp[n];
}


// top down approach using DP
int ladderTD(int n, int k, int *dp){
    if(n==0)
        return 1;

    if(n<0)
        return 0;
        
    if(dp[n]!=0)
        return dp[n];

    int ans=0;
    for(int i=1;i<=k;i++)
        ans+=ladderTD(n-i,k,dp);
    
    return dp[n] = ans;
}


int laddersOptimized(int n, int k){
    int dp[100]= {0};

    dp[0]=dp[1]=1;

    for(int i=2;i<=k;i++){
        dp[i] = 2*dp[i-1];
    }

    for(int i=k+1;i<=n;i++){
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }

    return dp[n];

}


int main()
{   
    int n,k;
    cin>>n>>k;
    int dp[100]={0};

    cout<<ladderTD(n,k,dp)<<"\n";
    cout<<laddersOptimized(n,k);

    return 0;
}