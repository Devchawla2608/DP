// Longest Increasing Subsequence

// Given an integer array nums, return the length of the longest strictly increasing 
// subsequence    

// Link -> https://leetcode.com/problems/longest-increasing-subsequence/

int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , 1);
        vector<int> hash(n);
        int mx = 0;
        int lastIndex = -1;
        for(int i = 0 ;i<n ; i++){
            hash[i] = i;
            for(int j = 0;j<i ; j++){
                if(nums[j] < nums[i] && (1 + dp[j]) > dp[i]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i] > mx){
                mx = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        reverse(temp.begin() , temp.end());
        for(int i=0; i<temp.size(); i++){
            cout<<temp[i]<<" ";
        }
        cout<<endl;
    return ans;
    }