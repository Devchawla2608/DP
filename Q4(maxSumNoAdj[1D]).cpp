    
// Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i]amount of money present in it.

// Link -> https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
    
//!  Recursion 
o(2**N) + O(N);
    
    int f(int index , int arr[] , int n){
        if(index == 0) return arr[index];
        int pick = f(index-2 , arr , n ) + arr[index];
        int notPick = f(index-1 , arr , n );
        return max(pick , notPick);
    }
    
    int FindMaxSum(int arr[], int n)
    {
        return f(n-1 , arr , n );
    }

// Memoization (ON) + 2*O(N)

    int f(int index , int arr[] , int n, vector<int> &dp){
        if(index <0) return 0;
        if(index == 0) return arr[index];
        if(dp[index] != -1) return dp[index];
        int pick = f(index-2 , arr , n , dp) + arr[index];
        int notPick = f(index-1 , arr , n , dp);
        return dp[index] = max(pick , notPick);
    }
    
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n , -1);
        return f(n-1 , arr , n , dp);
    }

// Tabulation (ON) + 2*O(N)

    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n , -1);
        dp[0] = arr[0];
        dp[1] = max(arr[0] , arr[1]);
        for(int i = 2;i<n ; i++){
            int notPick = dp[i-1];
            int pick = dp[i-2] + arr[i];
            dp[i] = max(pick , notPick);
        }
        return dp[n-1];
    }

// Space Optimization (ON) + 2*O(N)

    int FindMaxSum(int arr[], int n)
    {
        if(n == 0) return 0;
        if(n == 1) return arr[0];
        int pre = arr[0];
        int cur = max(arr[0] , arr[1]);
        for(int i = 2;i<n ; i++){
            int notPick = cur;
            int pick = pre + arr[i];
            pre = cur;
            cur  = max(pick , notPick);
        }
        return cur;
    }