// Recursion 

// Here the basecase is very important because what is nums[i] >= 0 then we have to consider 0 as well 

// Recursion 
Time Complexity -> O(2**N)
Space Complexity -> O(N*K) + O(N) ; 

int solve(int index , int target , vector<int> &arr){
    if(index == 0){
        if(target == 0 && arr[0] == 0) return 2;
        if(target == 0 || arr[0] == target) return 1;
        return 0;
    }
    int notPick = solve(index-1 , target  , arr );
    int pick = 0;
    if(target >= arr[index]) pick = solve(index-1, target - arr[index] , arr );
    return notPick + pick; 
}
int findWays(vector<int> &arr, int tar)
{   
    return   solve(arr.size()-1 , tar , arr);
}

// Memoization 
Time Complexity -> O(N**K) + O(N)
Space Complexity -> O(N*K); 
int solve(int index , int target , vector<int> &arr ,vector<vector<int>> &dp){
    if(index == 0){
        if(target == 0 && arr[0] == 0) return 2;
        if(target == 0 || arr[0] == target) return 1;
        return 0;
    }
    if(dp[index][target] != -1) return dp[index][target];
    int notPick = solve(index-1 , target  , arr , dp);
    int pick = 0;
    if(target >= arr[index]) pick = solve(index-1, target - arr[index] , arr , dp);
    return dp[index][target] = notPick + pick; 
}
int findWays(vector<int> &arr, int tar)
{   
    vector<vector<int>> dp(arr.size() , vector<int>(tar +1 , -1));
    return   solve(arr.size()-1 , tar , arr, dp);
}

// Tabulation 
Time Complexity -> O(N**K) + O(N)
Space Complexity -> O(N*K); 
int findWays(vector<int> &arr, int tar)
{   
    vector<vector<int>> dp(arr.size() , vector<int>(tar +1 , 0));
    for(int i =0  ;i<tar+1 ; i++){
        if(i == 0 && arr[0] == 0) dp[0][0] = 2;
        else if(i == 0 || i == arr[0]) dp[0][i] = 1;
        else dp[0][i] = 0;
    }
    for(int i = 1 ;i< arr.size() ; i++){
        for(int j = 0;j<=tar ; j++){
            int notPick = dp[i-1][j];
            int pick = 0;
            if(j >= arr[i]) pick = dp[i-1][j-arr[i]];
            dp[i][j] = notPick + pick;   
        }
    }
    return dp[arr.size()-1][tar];
}

// Space Optimization 
Time Complexity -> O(N**K) + O(N)
Space Complexity -> 2*O(N); 

int findWays(vector<int> &arr, int tar)
{   
    vector<int> pre(tar+1 , 0);
    vector<int> temp(tar+1 , 0);
    for(int i =0  ;i<tar+1 ; i++){
        if(i == 0 && arr[0] == 0) pre[0] = 2;
        else if(i == 0 || i == arr[0]) pre[i] = 1;
        else pre[i] = 0;
    }
    for(int i = 1 ;i< arr.size() ; i++){
        for(int j = 0;j<=tar ; j++){
            int notPick = pre[j];
            int pick = 0;
            if(j >= arr[i]) pick = pre[j-arr[i]];
            temp[j] = notPick + pick;   
        }
        pre = temp;
    }
    return pre[tar];
}