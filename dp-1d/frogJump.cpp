#include<iostream>
#include<climits>
#include<vector>
using namespace std;


//topdown approach
int frogJump(vector<int> arr, int n, int i, vector<int> &dp){
    if(i==n-1)
        return 0;

    if(i>=n)
        return INT_MAX;

    if(dp[i]!=0)
        return dp[i];
    
    int ans=INT_MAX;

    for(int j=1;j<=2;j++){
        int subProb = frogJump(arr,n,i+j,dp);

        if(subProb!=INT_MAX){
            ans = min(ans,subProb+abs(arr[i]-arr[i+j]));
        }
    }
    return dp[i]=ans;
}


//bottom up approach
int minCost(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n,0);

    dp[1] = abs(arr[1]-arr[0]);

    for(int i=2;i<n;i++){
        int j1 = dp[i-1]+abs(arr[i-1]-arr[i]);
        int j2 = dp[i-2]+abs(arr[i-2]-arr[i]);
        dp[i] = min(j1,j2);
    }
        return dp[n-1];
}



int main()
{   vector<int> heights{30,10,60,10,60,50};
    int n=heights.size();
    vector<int> dp(n+1,0);
   
    cout<<"Minimum cost incurred: "<<frogJump(heights,n,0, dp)<<endl<<minCost(heights);
    return 0;
}