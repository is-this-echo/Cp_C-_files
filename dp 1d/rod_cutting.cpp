#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// recursive solution
int maxProfit(int n, int price[]){
    if(n<=0){
        return 0;
    }

    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans = max(ans,maxProfit(n-i-1,price)+price[i]);
    }
    return ans;
}


// top down approach
int maxProfitTD(int n, int *price, vector<int> &dp){

    if(n==0)
        return 0;
    
    if(dp[n]!=0)
        return dp[n];
    
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        ans = max(ans, maxProfit(n-i-1, price)+price[i]);
    }
    return dp[n] = ans;
}

// bottom up approach
int maxProfitBU(int n, int price[]){
    vector<int> dp(n+1,INT_MIN);
    dp[0]=0;
    dp[1]= price[0];

    for(int i=2;i<=n;i++){
       for(int j=i-1;j>=0;j--){
           dp[i] = max(dp[i],dp[j]+price[i-j-1]);
       }
    }
    return dp[n];
}


int main()
{
    int price[] = {1,5,8,9,10,17,17,20};
    // int price[]  = {3,5,8,9,10,17,17,20};
    int n=8;
    vector<int> dp(n+1,0);

    cout<<maxProfitTD(n, price,dp)<<endl;
    cout<<maxProfit(n,price)<<endl;
    cout<<maxProfitBU(n,price);

    return 0;
}