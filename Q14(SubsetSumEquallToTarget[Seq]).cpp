// Subset Sum Equal To K

// You are given an array/list 'ARR' of 'N' positive integers and an
// integer 'K'. Your task is to check if there exists a subset in 'ARR'
// with a sum equal to 'K'.
// Note: Return true if there exists a subset with sum equal to 'K'.
// Otherwise, return false.

// Recursion Try All Subsets/subsequence 
// Intution We will do pick or not pick 

//  Recursion 
// Time Complexity -> O(2**N)
// Space Complexity -> O(N); 

bool solve(int index , int k , vector<int> &arr){
    //Bases Cases and other cases
    if(k == 0) return true;
    if(index == 0) return arr[index] == k;

    bool notTake = solve(index -1 , k , arr);

    bool take = false;
    if(k >= arr[index]) take = solve(index - 1 , k-arr[index] , arr );
    return take || notTake ;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return solve(n-1 , k , arr);
}

// Memoization
Time Complexity -> O(N*K)
Space Complexity -> O(N*K) + O(N); 

bool solve(int index , int k , vector<int> &arr , vector<vector<int>> &dp){
    //Bases Cases and other cases
    if(k == 0) return true;
    if(index == 0) return arr[index] == k;
    if(dp[index][k] != -1) return dp[index][k];
    bool notTake = solve(index -1 , k , arr , dp);
    bool take = false;
    if(k >= arr[index]) take = solve(index - 1 , k-arr[index] , arr , dp);
    return dp[index][k] =  take || notTake ;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n , vector<int>(k+1 , -1));
    return solve(n-1 , k , arr , dp);
}


// Tabulation 
Time Complexity -> O(N*K)
Space Complexity -> O(N*K);

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n , vector<int>(k+1 , 0));
    for(int i = 0;i<n ; i++) dp[i][0] = true;
    for(int i = 0;i<=k ; i++){
        if(arr[0] == i) dp[0][i] = true;
    }
    for(int i = 1 ;i<n ; i++){
        for(int j = 1 ;j<=k ; j++){
            bool notTake = dp[i-1][j];
            bool take = false;
            if(j >= arr[i]) take = dp[i-1][j-arr[i]];
            dp[i][j] =  take | notTake ;
        }
    }
    return dp[n-1][k];
}

// Space Optimization 
Time Complexity -> O(N*K)
Space Complexity -> 2*O(k); 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> pre(k+1 , 0);
    vector<bool> cur(k+1 , 0);
    for(int i = 0;i<=k ; i++){
        if(arr[0] == i) cur[i] = true;
    }
    pre[0] = true;
    cur[0] = true; 
    for(int i = 1 ;i<n ; i++){
        for(int j = 1 ;j<=k ; j++){
            bool notTake = pre[j];
            bool take = false;
            if(j >= arr[i]) take = pre[j-arr[i]];
            cur[j] =  take | notTake ;
        }
    pre = cur;
    }
    return pre[k];
}
