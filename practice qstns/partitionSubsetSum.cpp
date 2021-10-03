#include<iostream>
#include<vector>
using namespace std;

// wrong solution , not yet completed
int subsetsum(vector<int> &nums, int n,int sumtotal, int sum){
    if(n==0)
        return 0;

    int sum1 = subsetsum(nums,nums.size()-1,sumtotal,sum+nums[n-1]);
    int sum2 = subsetsum(nums,nums.size()-1,sumtotal,sum);

    return sum1 == sum2 && sum1+sum2==sumtotal;
}

bool canPartition(vector<int>& nums) {
    int sumtotal=0,n=nums.size();
    for(int i=0;i<n;i++)
        sumtotal+=nums[i];

    return subsetsum(nums,n,sumtotal,0);
    
}


int main()
{
    vector<int> nums = {1,5,11,5};
    cout<<canPartition(nums);

    return 0;
}