

// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

// Link -> https://leetcode.com/problems/longest-common-subsequence/ 

Intution -> In this we have to find longest comman subsequence and we know that subsequence is the string is continuous or not continuous but follow the order

// To solve the questio the brute force is the
// 1.) Generating the all subsequences and then match which is not possibleso 
// 2.) Generate and find in way 
// 3.) Memozation
// Tabulaion
// Space Optimization


//! Recursive 
Time 
int solve(int index1 , int index2 , string text1 , string text2){
        if(index1 == -1 || index2 == -1){
            return 0;
        }
        int result = 0;
        if(text1[index1] == text2[index2]){
            result = 1 + solve(index1-1 , index2-1 , text1 , text2);
        }else{
            result = 0 + max(solve(index1-1 , index2 , text1 , text2) , solve(index1 , index2 -1 , text1 , text2));
        }
        return result;
    }

    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1.size()-1 , text2.size()-1 , text1 , text2);
    }


//! Memoization

int solve(int index1 , int index2 , string text1 , string text2 , vector<vector<int>> &dp){
        if(index1 < 0 || index2 < 0){
            return 0;
        }
        if(dp[index1][index2] != -1) return dp[index1][index2];
        int result = 0;
        if(text1[index1] == text2[index2]){
            result = 1 + solve(index1-1 , index2-1 , text1 , text2 , dp);
        }else{
            result = 0 + max(solve(index1-1 , index2 , text1 , text2 , dp) , solve(index1 , index2 -1 , text1 , text2 , dp));
        }
        return dp[index1][index2] = result;
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() , vector<int>(text2.size() , -1));
        return solve(text1.size()-1 , text2.size()-1 , text1 , text2 , dp);
    }

// ! Tabulation
//todo Here we know that the base case is -1 so we do shifting in dp array like did in this code see the code 

int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1 , vector<int>(text2.size()+1 , 0));
        for(int i = 1 ; i<=text1.size() ; i++){
            for(int j = 1 ; j<=text2.size() ; j++){
                int result = 0;
                if(text1[i-1] == text2[j-1]){
                    result = 1 + dp[i-1][j-1];
                }else{
                    result = max(dp[i-1][j] , dp[i][j-1]);
                }
            dp[i][j] = result;
            }
        }
        return dp[text1.size()][text2.size()];
    }
//! Space Optimized 

int longestCommonSubsequence(string text1, string text2) {
        vector<int> pre(text2.size()+1 , 0);
        vector<int> temp(text2.size()+1 , 0);
        for(int i = 1 ; i<=text1.size() ; i++){
            for(int j = 1 ; j<=text2.size() ; j++){
                int result = 0;
                if(text1[i-1] == text2[j-1]){
                    result = 1 + pre[j-1];
                }else{
                    result = max(pre[j] , temp[j-1]);
                }
            temp[j] = result;
            }
            pre = temp;
        }
        return pre[text2.size()];
    }