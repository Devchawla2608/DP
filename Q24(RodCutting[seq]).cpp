// Rod Cutting

// Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.
// Note: Consider 1-based indexing.

    int f(int index , int arr[] , int n , vector<vector<int>> &dp){
        if(n == 0) return 0;
        if(index == 0){
            if(n%(index+1) == 0){
                return (n/(index+1))*arr[0];
            }
            return 0;
        }
        if(dp[index][n] != -1) return dp[index][n];
        int pick = 0;
        if(n >= index+1){
            pick = f(index , arr , n-(index+1) , dp) + arr[index];
        }
        int notPick = f(index-1 , arr , n , dp);
        return dp[index][n] =  max(pick , notPick);
    }
  
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n , vector<int>(n+1 , -1));
        return f(n-1 , price , n , dp);
    }

    // Time Complexity -> 