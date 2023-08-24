// Wildcard Matching

// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Leetcode Link -> https://leetcode.com/problems/wildcard-matching/
 
//  Recursive Solution

    int f(int i , int j , string &pattern , string &text ){
        if(i<0 && j<0) return true;
        if(i<0 && j>= 0) return false;
        if(j<0 && i>=0){
            for(int ii = 0; ii<=i ; ii++){
                if(pattern[ii] != '*') return false;
            }
            return true;
        }
        if(pattern[i] == text[j] || pattern[i] == '?'){
            return f(i-1 , j-1 , pattern , text );
        }
        if(pattern[i] == '*'){
            return f(i-1 , j , pattern , text ) | f(i , j-1 , pattern , text );
        }
        return   false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        return f(m-1 , n-1 , p , s );
    }
 
    // Time Complexity -> O(2**N)
    // Space Complexity -> O(N)

//  Memoization

    int f(int i , int j , string &pattern , string &text , vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(i<0 && j>= 0) return false;
        if(j<0 && i>=0){
            for(int ii = 0; ii<=i ; ii++){
                if(pattern[ii] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(pattern[i] == text[j] || pattern[i] == '?'){
            return f(i-1 , j-1 , pattern , text, dp);
        }
        if(pattern[i] == '*'){
            return f(i-1 , j , pattern , text, dp) | f(i , j-1 , pattern , text, dp);
        }
        return dp[i][j] =  false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return f(m-1 , n-1 , p , s , dp);
    }

    Time Complexity -> O(N*M)
    Space Complexity -> O(N*M)