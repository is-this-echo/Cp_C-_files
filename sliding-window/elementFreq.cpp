// 1838. Frequency of the Most Frequent Element

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

# define ll long long

int maxFrequency(vector<int>& nums, int k) {
    // sorting  + sliding window 
    sort(nums.begin(),nums.end());
    
    int n= nums.size();
    ll l=0,r=0,maxlen=0,total=nums[0];
    
    while(r<n && l<=r){
        ll window_len = r-l+1;

        // expand window, we want to make all elements
        // inside the window same as the last element in window
        if(nums[r]*window_len <= total + k){
            maxlen = max(maxlen,window_len);
            r++;
            
            if(r<n)
                total+=nums[r];
        }
        // contract window
        else{
            total-=nums[l];
            l++;
        }         
    } 
    return maxlen;
}



int main()
{
    vector<int> nums = {1,1,1,2,2,4};
    int k=2;

    cout<<maxFrequency(nums,k);

    return 0;
}