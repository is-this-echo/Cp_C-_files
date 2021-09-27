#include<iostream>
#include<vector>
using namespace std;


// bottom up approach
int rob(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,0);

    dp[0]=nums[0];
    dp[1] =max(nums[0],nums[1]);

    for(int i=2;i<n;i++){
        dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[n-1];
}


int main()
{
    vector<int> arr = {2,1,1,2};
 
    cout<<"Max profit robber could make is: "<<rob(arr);

    return 0;
}