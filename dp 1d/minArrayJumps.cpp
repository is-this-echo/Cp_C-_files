#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// Top down approach
int minArrayJumps(vector<int> arr, vector<int> &dp, int n, int i=0){
    if(i==n-1)
        return 0;

    if(i>=n)
        return INT_MAX;

    if(dp[i]!=0)
        return dp[i];

    int ans=INT_MAX;
    for(int jump=1;jump<=arr[i];jump++){
        int subProb = minArrayJumps(arr,dp,n,i+jump);
        if(subProb!=INT_MAX)
            ans = min(ans,subProb+1);
    }
    return dp[i]=ans;
}



int main()
{
    vector<int> arr{3,4,2,1,2,3,7,1,1,1,2,5};
    int n=arr.size();
    vector<int> dp(n,0);

    cout<<minArrayJumps(arr,dp,n)<<endl;

    for(auto x : dp)
        cout<<x<<" ";

    return 0;
}