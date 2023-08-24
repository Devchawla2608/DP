// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.    

// Link -> https://leetcode.com/problems/largest-divisible-subset/

vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int> dp(nums.size() , 1);
        vector<int> hash(nums.size() , 1);
        int last_index = 0;
        int maxi = 1;
        for(int i = 0 ;i< nums.size() ; i++){
            hash[i] = i;
            for(int j = 0 ; j< i ; j++){
                if(nums[i]% nums[j] == 0 && dp[i] < dp[j]+1){
                    dp[i] = max(dp[i] , dp[j] + 1);
                    hash[i] = j;
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                last_index = i;
            }
        }
    vector<int> result;
            result.push_back(nums[last_index]); 
    while(hash[last_index] != last_index){
                    last_index  = hash[last_index];
            result.push_back(nums[last_index]); 
    }
    reverse(result.begin() , result.end());
    return result;
    }

    Time Complexity: O(n^2)
    Space Complexity: O(n)