// leetcode 416

#include<iostream>
#include<vector>
using namespace std;

// 0/1 knapsack problem
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



int main()
{   
    vector<int> nums{1,5,11,5};

    if(canPartition)
        cout<<"True";
    else
        cout<<"False";
  
    
    return 0;
}