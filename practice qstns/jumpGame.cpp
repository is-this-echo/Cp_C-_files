#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



// dp approach, O(n^2) time
 bool traverse(vector<int> &nums, unordered_map<int,bool> &m, int i, int n){
    if(i==n-1)
        return true;
    if(i>=n)
        return false;
    
    if(m.find(i)!=m.end())
        return m[i];
    
    bool ans=false;
    for(int jump=1;jump<=nums[i];jump++){
        bool x = traverse(nums,m,i+jump,n);
        ans  = ans || x;
    } 
    return m[i]=ans;
}
    
    
bool canJump(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,bool> m;
    
    return traverse(nums,m,0,n);
}


// greedy approach, O(n) time
bool canJump(vector<int>& nums) {
    int n= nums.size();
    int goal = n-1;
    
    for(int i=goal-1;i>=0;i--){
        if(i+nums[i]>=goal)
            goal=i;
    } 
    return goal==0;
}



int main()
{   
    vector<int> a = {3,2,1,0,4};
    cout<<canJump(a)<<"\n";
   // cout<<canJumpGreedy(a);
    
    return 0;
}