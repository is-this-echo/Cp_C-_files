#include<iostream>
#include<vector>
using namespace std;

// TC = O(k^n), SC = O(1)
// Tree depth max will be n and at each level k calls are made from the nodes
int ladderRec(int n, int k)
{
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    int ans = 0;
    for (int jump = 1; jump <= k; ++jump)
    {
        ans += ladderRec(n - jump, k);
    }
    return ans;
}

// TC = O(nk), SC = O(n)
// bottom up approach using DP
int ladderBU(int n, int k){
    int dp[100]={0};
    dp[0]=1;

    for (int i=1;i<=n;i++){
        for (int jump = 1; jump <= k; jump++)
        {
            if (i - jump >= 0)
                dp[i] += dp[i - jump];
        }
    }
    return dp[n];
}

// TC = O(nk), SC = O(n)
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

// TC = O(n), SC = O(n)
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
    cout<<ladderBU(n,k) << "\n";
    cout << ladderRec(n, k);

    return 0;
}