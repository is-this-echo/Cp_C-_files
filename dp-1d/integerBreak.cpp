
// Leetcode 343


#include<iostream>
using namespace std;

#define ll long long
#define mod 998244353
double eps = 1e-12;

// bottom up dp soln, TC = O(n^2)
int integerBreak(int n) {
    int *dp= new int[n+1];     
    dp[1]=1;

    for(int num=2;num<=n;num++){
        if(num!=n)
            dp[num]=num;
        else
            dp[num]=0;
        
        for(int i=1;i<num;i++){
            dp[num]=max(dp[num],dp[i]*dp[num-i]);
        } 
    }      
    return dp[n];
}


// top down dp soln, TC = O(n^2)
int dfs(int dp[], int n, int num){
    if(dp[num]!=0)
        return dp[num];
    
    if(num==n)
        dp[num]=0;
    else
        dp[num]=num;
    
    for(int i=1;i<num;i++){
        dp[num] = max(dp[num], dfs(dp,n,i)*dfs(dp,n,num-i));
    }
    return dp[num];
}


int integerBreakTD(int n){
    int *dp = new int[n+1]{0};
    dp[0]=0; dp[1]=1;

    return dfs(dp,n,n);
}




int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;

    cout<<integerBreak(n)<<'\n';
    cout<<integerBreakTD(n)<<'\n';
    
    return 0;
}