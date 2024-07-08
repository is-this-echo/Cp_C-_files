/* Debjyoti Ghosh*/
#include<iostream>
#include<vector>
using namespace std;


/*  Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order. */
void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int n){ 
    if(n==0){
        ans.push_back(temp);
        return;
    }
    // taking the last element in subset
    temp.push_back(nums[n-1]);
    helper(nums, ans,temp,n-1);

   // not taking the last element in the subset, we have taken it once, so need to pop back
    temp.pop_back();
    helper(nums,ans,temp,n-1);
}


vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    int n = nums.size();
    
    helper(nums,ans,temp,n);
    return ans;
}


int main()
{   vector<int> nums{1,25,6};
    auto output = subsets(nums);

    for(auto x : output){
        for(int i : x)
            cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}