// 322. Coin Change

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

// Leetcode Link -> https://leetcode.com/problems/coin-change/

// Recursion 
// We can not define the time complexity 
Time Complexity -> O(2**N)
space compl -> O(N);
    int f(int index , int amount , vector<int> &arr){
        if(amount == 0) return 0;
        if(index == 0){
            if(amount%arr[0] == 0) return amount/arr[0];
            return 1e9;
        }
        int notPick = f(index-1 , amount , arr );
        int pick = 1e9;
        if(amount >= arr[index]) pick = f(index , amount - arr[index] , arr )+1;
        return  min(pick , notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int result  = f(n-1 , amount , coins);
        if(result == 1e9) return -1;
        return result;
    }

// Memoization
Time Complexity -> O(N*M)
space compl -> O(N*M) + O(N);
int f(int index , int amount , vector<int> &arr , vector<vector<int>> &dp){
        if(amount == 0) return 0;
        if(index == 0){
            if(amount%arr[0] == 0) return amount/arr[0];
            return 1e9;
        }
        if(dp[index][amount] != -1) return dp[index][amount];
        int notPick = f(index-1 , amount , arr , dp);
        int pick = 1e9;
        if(amount >= arr[index]) pick = f(index , amount - arr[index] , arr , dp)+1;
        return dp[index][amount] = min(pick , notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() , vector<int>(amount +1 , -1));
        int n = coins.size();
        int result  = f(n-1 , amount , coins , dp);
        if(result == 1e9) return -1;
        return result;
    }