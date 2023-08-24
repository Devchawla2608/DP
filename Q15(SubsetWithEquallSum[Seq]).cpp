
// This question is same as the question sum is equall to k becuase we are diving the subset into two subset and find it is possible or not to divde the array into to equall sum 
//  so here k = sum/2

// We can do same all the stuff like recursion , memoization , tabulation , space optimization and time complexity -> O(N*K) + O(N) for fiding the sum 

// Time Complexity -> O(N*K)
// Space Complexity -> O(1); 
#include <bits/stdc++.h> 

// ************* Recursion **************

Time Complexity -> O(2**N)
Space Complexity -> O(N);

bool f(int index , int k , vector<int> &arr , vector<vector<int>> &dp){
    
    if(k == 0) return true;
    if(index == 0) return arr[0] == k;
    if(dp[index][k] != -1) return dp[index][k];
    bool notPick = f(index -1 , k , arr);
    bool pick = false;
    if(arr[index] <= k) pick = f(index-1 , k-arr[index] , arr );
    return  pick | notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return f(n-1 , k , arr);
}

    bool canPartition(vector<int>& nums , int n) {
        int sum = 0;
        for(int i = 0 ;i< nums.size() ; i++){
            sum +=nums[i];
        }
        if(sum%2 != 0) return false;
        // return true;
        return subsetSumToK(nums.size() , sum/2 , nums);
    }

//****************  Memoization *************

// Time Complexity -> O(N*K)
// Space Complexity -> O(N*K) + O(N);

bool f(int index , int k , vector<int> &arr , vector<vector<int>> &dp){
    
    if(k == 0) return true;
    if(index == 0) return arr[0] == k;
    if(dp[index][k] != -1) return dp[index][k];
    bool notPick = f(index -1 , k , arr , dp);
    bool pick = false;
    if(arr[index] <= k) pick = f(index-1 , k-arr[index] , arr , dp);
    return dp[index][k] = pick | notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n , vector<int>(k+1 , -1));
    return f(n-1 , k , arr , dp);
}

    bool canPartition(vector<int>& nums , int n) {
        int sum = 0;
        for(int i = 0 ;i< nums.size() ; i++){
            sum +=nums[i];
        }
        if(sum%2 != 0) return false;
        // return true;
        return subsetSumToK(nums.size() , sum/2 , nums);
    }

//****************  Tabulation  *************

Time Complexity -> O(N*K)
Space Complexity -> O(N*K);

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<int> pre(k+1 , 0);
    vector<vector<int>> dp(n , vector<int>(k+1 , 0));
    for(int i = 0 ;i< n ; i++) dp[i][0] = 1;
    if(k>= arr[0]) dp[0][arr[0]] = 1;
    for(int i = 1 ;i< n ;i++){
        for(int j = 1 ;j<=k ; j++){
            bool notPick =  dp[i-1][j];
            bool pick = false;
            if(arr[i] <= j)pick = dp[i-1][j-arr[i]];
            dp[i][j] = notPick|pick;
        }
    }
    return dp[n-1][k];
}
 
     bool canPartition(vector<int>& nums , int n) {
        int sum = 0;
        for(int i = 0 ;i< nums.size() ; i++){
            sum +=nums[i];
        }
        if(sum%2 != 0) return false;
        // return true;
        return subsetSumToK(nums.size() , sum/2 , nums);
    }

// ************** space optimization *************** 

// TIme Complexity -> O(N*K)
// Space Complexity -> O(2*K);

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<int> pre(k+1 , 0);
    pre[0] = 1;
    vector<int> temp(k+1 , 0);
    temp[0] = 1;
    if(k>= arr[0]) pre[arr[0]] = 1;
    for(int i = 1 ;i< n ;i++){
        for(int j = 1 ;j<=k ; j++){
            bool notPick =  pre[j];
            bool pick = false;
            if(arr[i] <= j)pick = pre[j-arr[i]];
            temp[j] = notPick|pick;
        }
        pre = temp;
    }
    return pre[k];
}
    bool canPartition(vector<int>& nums , int n) {
        int sum = 0;
        for(int i = 0 ;i< nums.size() ; i++){
            sum +=nums[i];
        }
        if(sum%2 != 0) return false;
        // return true;
        return subsetSumToK(nums.size() , sum/2 , nums);
    }





