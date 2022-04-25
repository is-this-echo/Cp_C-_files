#include<iostream>
#include<vector>
using namespace std;


int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    int lis=1;
    vector<int> dp(n,1); 
    
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(nums[j]<nums[i])
                dp[i] = max(dp[i],dp[j]+1);
                lis = max(lis,dp[i]);
        }
    }
    return lis;
}



int main()
{   
    vector<int> arr {1,3,6,7,9,4,10,5,6};

    cout<<"Length of LIS is "<<lengthOfLIS(arr);
    
    return 0;
}