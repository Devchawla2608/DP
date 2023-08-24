
// Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:
// Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
// You should perform the cuts in order, you can change the order of the cuts as you wish.
// The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

// Link -> https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

// Return the minimum total cost of the cuts.

 
// Recursion 
    int f(int i , int j , vector<int> &arr , vector<vector<int>> &dp){
        if(i>j) return 0;
        int val = INT_MAX;
        if(dp[i][j] != -1 ) return dp[i][j];
        for(int k = i ; k<=j ; k++){
            int steps = arr[j+1] - arr[i-1] + f(i , k-1 , arr , dp) + f(k+1 , j , arr , dp);
            val = min(val , steps);
        }
        return dp[i][j] = val;
    }

    int minCost(int n, vector<int>& arr) {
        vector<vector<int>> dp(n , vector<int>(n , -1));
        arr.push_back(n);
        arr.insert(arr.begin() , 0);
        sort(arr.begin() , arr.end());
        return f( 1 , arr.size()-2  , arr , dp);
    }
// Memoization 
    int f(int i , int j , vector<int> &arr , vector<vector<int>> &dp){
        if(i>j) return 0;
        int val = INT_MAX;
        if(dp[i][j] != -1 ) return dp[i][j];
        for(int k = i ; k<=j ; k++){
            int steps = arr[j+1] - arr[i-1] + f(i , k-1 , arr , dp) + f(k+1 , j , arr , dp);
            val = min(val , steps);
        }
        return dp[i][j] = val;
    }

    int minCost(int n, vector<int>& arr) {
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));
        arr.push_back(n);
        arr.insert(arr.begin() , 0);
        sort(arr.begin() , arr.end());
        return f( 1 , arr.size()-2  , arr , dp);
    }


// Tabulation 
  int minCost(int n, vector<int>& arr) {
        int c = arr.size();
        arr.push_back(n);
        arr.insert(arr.begin() , 0);
        sort(arr.begin() , arr.end());
        vector<vector<int>> dp(c+2 , vector<int>(c+2 , 0));
        for(int i = c ; i>=1 ; i--){
            for(int j = 1 ; j<=c ; j++){
                if(i>j) continue;
                int val = 1e9;
                for(int k = i ; k<=j ; k++){
                    int steps = arr[j+1] - arr[i-1] + dp[i][k-1] + dp[k+1][j];
                    val = min(val , steps);
                }
                dp[i][j] = val;
            }
        }
        return dp[1][c];
    }