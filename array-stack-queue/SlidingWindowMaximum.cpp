# include <iostream>
# include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            // Remove indices outside the window
            if (!dq.empty() && dq.front() <= i - k) 
                dq.pop_front();

            // Maintain decreasing order in deque
            // by removing elements smaller than the current element
            while (!dq.empty() && nums[dq.back()] <= nums[i]) 
                dq.pop_back();

            // Push current element to deque
            dq.push_back(i);

            // Add maximum for the current window
            if (i >= k - 1) 
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};


/*
https://leetcode.com/discuss/post/968803/bloomberg-onsite-stock-change-notificati-nio5/
*/
  deque<int>max_q;
    deque<int>min_q;
    
    for(int i = 0;i<n;i++) {
        while (!max_q.empty() && max_q.front() <= i-y) max-q.pop_front();
        while (!min_q.empty() && min_q.front() <= i-y) min_q.pop_front();
        
        while (!max_q.empty() && nums[max_q.back()] <= nums[i]) max_q.pop_back();
        while (!min_q.empty() && nums[min_q.back()] >= nums[i]) min_q.pop_back();
        
        max_q.push_back(i);
        min_q.push_back(i);
        
        if(i >= y-1){
            int curr_max = nums[max_q.front()];
            int curr_min = nums[min_q.front()];
            bool ans = curr_max - curr_min > x;
            
            threshold_reached.push_back(ans);
        }
    }
    
  return threshold_reached;
}