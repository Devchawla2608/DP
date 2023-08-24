// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.
// The answer is guaranteed to fit into a signed 32-bit integer.  

//  Recursion
// Time Complexity -> Can Not say but kind of (2**N);
// Space Compleixty -> O(N)

int f(int index , int amount , vector<int> &arr  ){
        if(amount == 0) return 1;
        if(index == 0){
            if(amount%arr[0] == 0) return 1;
            return 0;
        }
        int notPick = f(index-1 , amount , arr );
        int pick = 0;
        if(amount >= arr[index]) pick = f(index , amount - arr[index] , arr );
        return pick + notPick;
    }

    int change(int amount , vector<int>& coins) {
        int n = coins.size();
        int result  = f(n-1 , amount , coins);
        return result;
    }

//  Memozation
// Time Complexity -> O(N*M)
// Space Compleixty -> O(N*M) + O(N)

int f(int index , int amount , vector<int> &arr , vector<vector<int>> &dp){
        if(amount == 0) return 1;
        if(index == 0){
            if(amount%arr[0] == 0) return 1;
            return 0;
        }
        if(dp[index][amount] != -1) return dp[index][amount];
        int notPick = f(index-1 , amount , arr , dp);
        int pick = 0;
        if(amount >= arr[index]) pick = f(index , amount - arr[index] , arr , dp);
        return dp[index][amount] = pick + notPick;
    }

    int change(int amount , vector<int>& coins) {
        vector<vector<int>> dp(coins.size() , vector<int>(amount +1 , -1));
        int n = coins.size();
        int result  = f(n-1 , amount , coins , dp);
        return result;
    }

// Tabulation 
// Time Complexity -> O(N*M)
// Space Compleixty -> O(N*M) 
    int change(int amount , vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n , vector<int>(amount +1 , 0));
        for(int i = 0 ;i<n ; i++) dp[i][0] = 1;
        for(int i = 0 ;i<=amount ; i++){
            if(i%arr[0] == 0) dp[0][i] = 1;
            else dp[0][i] = 0;
        }

    for(int i = 1 ;i< n ; i++){
        for(int j = 1 ; j<=amount ; j++){
            int notPick = dp[i-1][j];
            int pick = 0;
            if(j >= arr[i]) pick = dp[i][j-arr[i]];
            dp[i][j] = pick + notPick;
        }
    }
    return dp[n-1][amount];
    }