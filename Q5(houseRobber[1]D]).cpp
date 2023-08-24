
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Link -> https://leetcode.com/problems/house-robber-ii/


// Recursion O(2**N) + O(N)*3
int f(int index , vector<int> &arr){
        if(index == -1) return 0;
        if(index == 0) return arr[index];
        int pick = f(index-2 , arr) + arr[index];
        int notPick = f(index-1 , arr);
        return max(pick , notPick);
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int> temp1;
        vector<int> temp2;
        for(int i = 0 ; i<n ; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        return max(f(temp1.size() -1 , temp1) , f(temp2.size() -1 , temp2) );
    }

// Memoization    O(N) + O(N)*3
int f(int index , vector<int> &arr , vector<int> &arr){
        if(index == -1) return 0;
        if(index == 0) return arr[index];
        if(dp[index] != -1) return dp[index];
        int pick = f(index-2 , arr) + arr[index];
        int notPick = f(index-1 , arr);
        return dp[index] = max(pick , notPick);
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int> temp1;
        vector<int> temp2;
        vector<int> dp1(nums.size()-1 , -1)
        vector<int> dp2(nums.size()-1 , -1)
        for(int i = 0 ; i<n ; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        return max(f(temp1.size() -1 , temp1 , dp1) , f(temp2.size() -1 , temp2 , dp2) );
    }

// Tabulation    O(N) + O(N)*3

    int FindMaxSum(int arr[], int n)
    {
        vector<int> temp1;
        vector<int> temp2;
        for(int i = 0 ; i<n ; i++){
            if(i != 0) temp1.push_back(arr[i]);
            if(i != n-1) temp2.push_back(arr[i]);
        }
        vector<int> dp1(n , -1);
        dp1[0] = temp1[0];
        dp1[1] = max(temp1[0] , temp1[1]);
        for(int i = 2;i<n ; i++){
            int notPick = dp1[i-1];
            int pick = dp1[i-2] + arr[i];
            dp1[i] = max(pick , notPick);
        }       
        vector<int> dp2(n , -1);
        dp2[0] = temp2[0];
        dp2[1] = max(temp2[0] , temp2[1]);
        for(int i = 2;i<n ; i++){
            int notPick = dp2[i-1];
            int pick = dp2[i-2] + arr[i];
            dp2[i] = max(pick , notPick);
        }
        return max(dp1[n-1] , dp2[n-1]);
    }