// Longest Increasing Subsequence

// Given an integer array nums, return the length of the longest strictly increasing 
// subsequence

// Link -> https://leetcode.com/problems/longest-increasing-subsequence/

//! **************** Recursion ***************

// nums = [10,9,2,5,3,7,101,18]

    int f(int index , vector<int> &nums , int preIndex ){
        if(index == nums.size()) return 0;
        int notPick = f(index+1 , nums , preIndex );
        int pick = 0;
        if(preIndex == -1 || nums[index]> nums[preIndex]){
            pick = f(index +1 , nums , index ) + 1;
        }
        return  max(notPick , pick);
    }


    int lengthOfLIS(vector<int>& nums) {
        return f(0 , nums , -1 );
    }

//todo Time Complexity -> O(2^N)
//todo Space Complexity -> O(N)

//! **************** Memoization ***************
// Here we did index shifiting because our parent can be -1;

    int f(int index , vector<int> &nums , int preIndex , vector<vector<int>> &dp){
        if(index == nums.size()) return 0;
        if(dp[index][preIndex +1] != -1) return dp[index][preIndex+1];
        int notPick = f(index+1 , nums , preIndex , dp);
        int pick = 0;
        if(preIndex == -1 || nums[index]> nums[preIndex]){
            pick = f(index +1 , nums , index , dp) + 1;
        }
        return dp[index][preIndex+1] =  max(notPick , pick);
    }


    int lengthOfLIS(vector<int>& nums) {
    vector<vector<int>> dp(nums.size() , vector<int>(nums.size()+1 , 0) )
        return f(nums.size()-1 , nums , -1 ,dp);
    }

//! **************** Tabulation ***************
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1 , vector<int>(nums.size()+1 , 0) );
        for(int i = nums.size()-1 ; i>=0 ; i--){
            for(int j = i-1 ; j>= -1 ; j--){
                int notPick = dp[i+1][j+1];
                int pick = 0;
                if(j == -1 || nums[i]> nums[j]){
                    pick = dp[i+1][i+1] + 1;
                }
                dp[i][j+1] =  max(notPick , pick);
            }
        }
        return dp[0][-1+1];
    }

//! **************** Space Optimization ***************
    int lengthOfLIS(vector<int>& nums) {
        vector<int> after(nums.size()+1 , 0);
        vector<int> temp(nums.size()+1 , 0);
        for(int i = nums.size()-1 ; i>=0 ; i--){
            for(int j = i-1 ; j>= -1 ; j--){
                int notPick = after[j+1];
                int pick = 0;
                if(j == -1 || nums[i]> nums[j]){
                    pick = after[i+1] + 1;
                }
                temp[j+1] =  max(notPick , pick);
            }
            after = temp;
        }
        return after[-1+1];
    }

//! **************** Extra Algorithm ***************

        int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i = 1 ;i< nums.size() ; i++){
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
            }
            else {
                int ind = lower_bound(temp.begin() , temp.end() , nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return temp.size();
    }

 