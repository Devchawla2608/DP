    
// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.Return the maximum coins you can collect by bursting the balloons wisely.

Link -> https://leetcode.com/problems/burst-balloons/


// Recursion 

int f(int i , int j , vector<int> nums ){
        if(j<i) return 0;
        int val = INT_MIN;
        for(int k = i ;k<=j ; k++){
            int ans = nums[k]*nums[i-1]*nums[j+1] +  f(i , k-1 , nums) + f(k+1 , j , nums );
            val = max(ans , val);
        }
        return val;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin() , 1);
        
        return f(1 , n , nums  );
    }

// Memoization 

int f(int i , int j , vector<int> nums, vector<vector<int>> &dp){
        if(j<i) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int val = INT_MIN;
        for(int k = i ;k<=j ; k++){
            int ans = nums[k]*nums[i-1]*nums[j+1] +  f(i , k-1 , nums , dp) + f(k+1 , j , nums , dp);
            val = max(ans , val);
        }
        return dp[i][j] = val;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin() , 1);
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
        
        return f(1 , n , nums , dp);
    }

    // Tabulation

    int maxCoins(vector<int>& arr) {
        arr.push_back(1);
        arr.insert(arr.begin() , 1);
        vector<vector<int>> dp(arr.size() , vector<int>(arr.size() , 0));
        for(int i = arr.size()-2 ; i>=1 ; i--){
            for(int j = 1 ; j<arr.size()-1 ; j++){
                int mx = INT_MIN;
                if(i>j){ dp[i][j] = 0 ; continue;}
                for(int k = i ; k<=j ; k++){
                int coin = arr[i-1]*arr[k]*arr[j+1] + dp[i][k-1] + dp[k+1][j];
                mx = max(mx , coin);
                }
                dp[i][j] =  mx;
            }
        }
        return dp[1][arr.size()-2];
    }