// Number of Longest Increasing Subsequenc
// Given an integer array nums, return the number of longest increasing subsequences.
// Notice that the sequence has to be strictly increasing

// Leetcode Link -> https://leetcode.com/problems/number-of-longest-increasing-subsequence/

    int findNumberOfLIS(vector<int>& nums) {
       vector<pair<int , int>> dp(nums.size() , {1 , 1});
       int mxln =1;
       for(int i = 0 ;i<nums.size() ; i++){
           for(int j = 0; j<i ; j++){
               if(nums[i] > nums[j]){
                   if(dp[j].first + 1 > dp[i].first){
                        dp[i] = {1+dp[j].first , dp[j].second}; 
                        mxln = max(mxln , dp[i].first);
                   }else if(dp[j].first + 1 == dp[i].first){
                       int c = dp[i].second;
                       dp[i] = {dp[i].first , c+dp[j].second};
                   }
               }else if(nums[i] == nums[j]){
                   
               }
           }
       }
       int cnt1 = 0;
        for(int i = 0 ;i< dp.size() ; i++){
            if(dp[i].first == mxln) {
                cnt1 += dp[i].second;
            }
        }
      return cnt1;
    }
    // Time Complexity: O(n^2)
    // Space Complexity: O(n)