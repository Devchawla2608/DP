// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
// The testcases are generated so that the answer will be less than or equal to 2 * 109.

// Link -> https://leetcode.com/problems/unique-paths-ii/

// Recursion O(2**N*M)
Space Complexity -> O(N-1) + O(M-1);

int f(int i , int j , vector<vector<int>>& arr){
        if(i == 0 && j == 0) return 1;
        if(i< 0 || j< 0) return 0;
        if(arr[i][j] == 1) return 0;
        int up = f(i-1 , j , arr );
        int left = f(i , j-1 , arr);
        return  up + left; 
    }

    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        if(arr[0][0] == 1 || arr[n-1][m-1] == 1) return 0;
        return f( n-1 , m-1, arr);
    }

// Memoization 
// Recursion O(N*M)
// Space Complexity -> O(N-1) + O(M-1) + O(N*M);

int f(int i , int j , vector<vector<int>>& arr , vector<vector<int>> &dp){
        if(i == 0 && j == 0) return 1;
        if(i< 0 || j< 0) return 0;
        if(arr[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j]; 
        int up = f(i-1 , j , arr , dp);
        int left = f(i , j-1 , arr , dp);
        return dp[i][j] = up + left; 
    }

    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        if(arr[0][0] == 1 || arr[n-1][m-1] == 1) return 0;
        return f( n-1 , m-1, arr , dp);
    }


// Tabulation
// Recursion O(N*M)
// Space Complexity ->  O(N*M);
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(n , vector<int>(m , 0));
        if(arr[0][0] == 1 || arr[n-1][m-1] == 1) return 0;
        dp[0][0] = 1;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ;j<m ; j++){
                if(i == 0 && j == 0) continue;
                    int up = 0;
                    int left = 0;
                    if(arr[i][j] == 1){ dp[i][j] = 0;}
                    if(i>=1) up = dp[i-1][j];
                    if(j>=1) left = dp[i][j-1];
                    dp[i][j] = up + left;   
            }
        }
        return dp[n-1][m-1];
    }
// Space Optimization 
// Recursion O(N*M)
// Space Complexity ->  2*O(M);
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<int> pre(m , 0);
        vector<int> cur(m , 0);
        if(arr[0][0] == 1 || arr[n-1][m-1] == 1) return 0;
        cur[0] = 1;
        pre[0] = 1;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ;j<m ; j++){
                if(i == 0 && j == 0) continue;
                    int up = 0;
                    int left = 0;
                    if(arr[i][j] == 1){ cur[j] = 0;}
                    if(i>=1) up = pre[j];
                    if(j>=1) left = cur[j-1];
                    cur[j] = up + left;   
            }
            pre = cur
        }
        return pre[m-1];
    }