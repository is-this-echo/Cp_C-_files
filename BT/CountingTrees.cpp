
// Count the number of BSTs that can be formed using numbers from 1 to N i.e with N nodes.

#include<iostream>
#include<vector>
using namespace std;

//recursive soln
int countBST(int N){
    if(N==0 || N==1)
        return 1;

    int ans=0;
    for(int i=1;i<=N;i++){
        ans+=countBST(i-1)*countBST(N-i);
    }
    return ans;
}

//top down dp soln
int countBSTTD(int N, int dp[]){
    if(N==0 || N==1)
        return 1;
    
    if(dp[N]!=0)
        return dp[N];
    
    int ans=0;
    for(int i=1;i<=N;i++){
        ans+=countBSTTD(i-1,dp)*countBSTTD(N-i,dp);
    }
    return dp[N]=ans;
}

// bottom up dp soln
int countBSTBU(int N){
    vector<int> dp(N+1,0);
    dp[0]=dp[1]=1;

    for(int n=2;n<=N;n++)
        for(int i=1;i<=n;i++)
            dp[n] += dp[i-1]*dp[n-i];
        
    return dp[N];
}


int main()
{   
    int N=4;
    int arr[100]={0};
    cout<<countBST(N)<<endl;
    cout<<countBSTTD(N,arr)<<endl;
    cout<<countBSTBU(N)<<endl;

    return 0;
}