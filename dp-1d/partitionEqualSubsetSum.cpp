// leetcode 416

#include<iostream>
#include<vector>
using namespace std;

// 0/1 knapsack problem, recursive approach
bool helper(vector<int> &nums,int totalSum, int subsetSum, int n){
    if(subsetSum == totalSum)
        return true;

    if(subsetSum>totalSum)
        return false;

    if(n==0)
        return false;

    return helper(nums,totalSum-nums[n-1],subsetSum+nums[n-1],n-1) ||
            helper(nums,totalSum,subsetSum,n-1);
}


bool canPartition(vector<int>& nums) {
    vector<int> temp;
    int totalSum=0,subsetSum=0;
    int n = nums.size();

    for(auto x : nums)
        totalSum+=x;

    return helper(nums,totalSum,subsetSum,n);
}


// dp approach
class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0)
            return false;
        
        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        
        for (int num : nums)
            for (int j = target; j >= num; --j)
                dp[j] = dp[j] || dp[j - num];
        
        return dp[target];
    }
};


int main()
{   
    vector<int> nums{1,5,11,5};

    if(canPartition)
        cout<<"True";
    else
        cout<<"False";

    return 0;
}