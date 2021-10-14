#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    int n=nums.size();
    
    if(n<3) return {};
    
    sort(nums.begin(),nums.end());
    
    for(int i=0;i<n-2;i++){
        int sum = -1*nums[i];
        int j=i+1, k=n-1;

        // to remove duplicates for ith index
        if(i!=0 && nums[i]==nums[i-1])
            continue;
        
        while(j<k && j!=k){
            int x = nums[j], y = nums[k];
            
            if(x+y==sum){
                ans.push_back({nums[i],x,y});

                // to remove duplicates for 2nd and 3rd elements, also we check that j<k 
                while(j+1<k && nums[j]==nums[j+1]) j++;
                while(k-1>j && nums[k]==nums[k-1]) k--;
                    
                j++,k--;
            }
            
            else if (x+y>sum)
                k--;
            else
                j++;
        }
    }
    return ans;
}



int main()
{
    vector<int> arr = {-1,0,1,2,-1,-4};
    auto output = threeSum(arr);

    for(auto rows : output){
        for(auto cols : rows)
            cout<<cols<<", ";
        cout<<endl;
    }
        
    
    return 0;
}