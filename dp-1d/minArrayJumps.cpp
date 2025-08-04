#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// 45. Jump Game II
// Top down dp approach
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

// Bottom-up approach
// dp[i] -> min number of steps required to reach (n-1)th index from ith index
class Solution {
public:
    int jump(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[n-1] = 0;

        for (int i = n - 2; i >= 0; --i)
        {   
            for (int jump = nums[i]; jump > 0; --jump)
            {
                int nextLoc = i + jump;
                if (nextLoc < n && dp[nextLoc] != INT_MAX)
                    dp[i] = min(dp[i], dp[nextLoc] + 1);
            }
        }
        return dp[0];
    }
};



// using BFS approach
int minJumpsBFS(vector<int> &arr){
    int l,r,ans;
    ans=0;
    l=r=0;
    int n = arr.size();

    while(r<n-1){
        int farthest=0;
        for(int i=l;i<=r;i++)
            farthest = max(farthest,arr[i]+i);
        
        l=r+1;
        r = farthest;
        ans++;
    }
    return ans;
}


int main()
{
    vector<int> arr{3,4,2,1,2,3,7,1,1,1,2,5};
    int n=arr.size();
    vector<int> dp(n,0);

    cout<<minArrayJumps(arr,dp,n)<<"\n";
    cout<<minJumpsBFS(arr)<<"\n";

   // for(auto x : dp)
  //      cout<<x<<" ";

    return 0;
}

