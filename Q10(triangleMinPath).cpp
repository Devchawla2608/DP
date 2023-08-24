// Triangle Min Path Sum

// Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

// Link -> https://leetcode.com/problems/triangle/

// Recursion

    int f(int i , int j , vector<vector<int>> &arr){
        if(i == arr.size()-1){
            return arr[i][j];
        }
        int down = f(i+1 , j , arr );
        int downRight = f(i+1 , j+1 , arr);
        return min(down , downRight) + arr[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        return f(0 , 0 , triangle);
    }

// Memoization 

    int f(int i , int j , vector<vector<int>> &arr , vector<vector<int>> &dp){
        if(i == arr.size()-1){
            return arr[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int down = f(i+1 , j , arr , dp);
        int downRight = f(i+1 , j+1 , arr , dp);
        return dp[i][j] = min(down , downRight) + arr[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        return f(0 , 0 , triangle , dp);
    }


// Tabulation  
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> dp(n , vector<int>(m , 0));
        for(int i = 0;i<m ; i++){
            dp[n-1][i] = triangle[n-1][i];
        }
        for(int i = n-2;i>=0 ; i--){
            for(int j = i;j>=0; j--){
                int down = dp[i+1][j];
                int downRight = dp[i+1][j+1];
                dp[i][j] = min(down , downRight) + triangle[i][j]; 
            }
        }
        return dp[0][0];
    }
