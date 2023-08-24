// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

// Link -> // https://www.codingninjas.com/studio/problems/minimum-path-sum_985349?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// Recursion 

// Time ->o(2**n*m)
// space -> O(M-1 + N-1); 

int solve(int i , int j , vector<vector<int>> &arr){
        if(i == 0 && j == 0) return arr[i][j]; 
        if(i<0 || j<0) return 1e9;
        int up = solve(i-1 , j ,arr);
        int left = solve(i , j-1 , arr);
        return min(left , up) + arr[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return solve(n-1 , m-1 , grid);
    }

// Memoization 
Time ->o(n*m)
space -> O(M-1 + N-1) + O(M*N); 

    int solve(int i , int j , vector<vector<int>> &arr , vector<vector<int>> &dp){
        if(i == 0 && j == 0) return arr[i][j]; 
        if(i<0 || j<0) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        int up = solve(i-1 , j , arr , dp);
        int left = solve(i , j-1 , arr , dp);
        return dp[i][j] =  min(left , up) + arr[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        return solve(n-1 , m-1 , grid , dp);
    }

// Tabulation 
Time ->o(n*m)
space ->  O(M*N) 
    int minPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(n , vector<int>(m , 0));
        for(int i = 0;i<n ; i++){
            for(int j = 0;j< m ; j++){
                if(i == 0 && j == 0) {dp[i][j] =  arr[i][j]; continue;} 
                int up = 1e9;
                int left = 1e9;
                if(i>=1) up =  dp[i-1][j];
                if(j>=1) left = dp[i][j-1];
                dp[i][j] =  min(left , up) + arr[i][j];
            }

        }
        return dp[n-1][m-1];
    }

// Space Optimization 

Time ->o(n*m)
// space ->  O(2*N) Due to  two one d array

    int minPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<int> pre(m , 0);
        vector<int> cur(m , 0);
        for(int i = 0;i<n ; i++){
            for(int j = 0;j< m ; j++){
                if(i == 0 && j == 0) {cur[j] =  arr[i][j]; continue;} 
                int up = 1e9;
                int left = 1e9;
                if(i>=1) up =  pre[j];
                if(j>=1) left = cur[j-1];
                cur[j] =  min(left , up) + arr[i][j];
            }
            pre = cur;
        }
        return pre[m-1];
    }

