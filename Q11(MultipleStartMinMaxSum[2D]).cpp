// Recursion
  int f(int i , int j , vector<vector<int>> &arr ){
    if(i<0 || j<0 || j>= arr[0].size()) return 1e9;
        if(i == 0){
            return arr[i][j];
        }
        int up = f(i-1 , j , arr);
        int left = f(i-1 , j-1 , arr );
        int right = f(i-1 , j+1 , arr );
        return  min(right , min(left , up)) + arr[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int result = 1e9;
        for(int i = 0;i<m ; i++){
                result = min(result , f(n-1 , i , matrix));
        }
        return result;
    }
};

Time complexity -> O(2**(M*N))*M
Space Complexity -> O(N)

// Memoization
  int f(int i , int j , vector<vector<int>> &arr , vector<vector<int>> &dp ){
    if(i<0 || j<0 || j>= arr[0].size()) return 1e9;
        if(i == 0){
            return arr[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int up = f(i-1 , j , arr , dp);
        int left = f(i-1 , j-1 , arr , dp);
        int right = f(i-1 , j+1 , arr , dp);
        return dp[i][j] =  min(right , min(left , up)) + arr[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int result = 1e9;
        vector<vector<int>> dp(n , vector<int>(m , -1));
        for(int i = 0;i<m ; i++){
                result = min(result , f(n-1 , i , matrix , dp));
        }
        return result;
    }
Time complexity -> O((M*N))*M
Space Complexity -> O(N) + O(N*M)

// Tabulation
  int f(int i , int j , vector<vector<int>> &arr , vector<vector<int>> &dp ){
    if(i<0 || j<0 || j>= arr[0].size()) return 1e9;
        if(i == 0){
            return arr[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int up = f(i-1 , j , arr , dp);
        int left = f(i-1 , j-1 , arr , dp);
        int right = f(i-1 , j+1 , arr , dp);
        return dp[i][j] =  min(right , min(left , up)) + arr[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int result = 1e9;
        for(int i = 0;i<m ; i++){
            vector<vector<int>> dp(n , vector<int>(m , -1));
                result = min(result , f(n-1 , i , matrix , dp));
        }
        return result;
    }
Time complexity -> O((M*N))*M
Space Complexity ->  O(N*M)