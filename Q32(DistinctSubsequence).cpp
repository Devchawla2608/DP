// Distinct Subsequences

// Given two strings s and t, return the number of distinct 
// subsequences of s which equals t.
// The test cases are generated so that the answer fits on a 32-bit signed integer.

// Recursion 

    int f(int index1 , int index2 , string s , string t ){
        if(index2<0 ) return 1;
        if(index1 <0) return 0;
        if(s[index1] == t[index2]){
            return f(index1-1 , index2 -1 , s , t) + f(index1 -1 , index2 , s , t);
        }else{
            return f(index1 -1 , index2 , s , t);
        }
    }
    int numDistinct(string s, string t) {
        return f(s.size()-1 , t.size()-1 , s , t);
    }

Time Complexity -> O(2^N)
Space Complexity -> O(N)

// Memoization

    int f(int index1 , int index2 , string s , string t , vector<vector<int>> &dp){
        if(index2<0 ) return 1;
        if(index1 <0) return 0;
        if(dp[index1][index2] != -1) return dp[index1][index2];
        if(s[index1] == t[index2]){
            return f(index1-1 , index2 -1 , s , t, dp) + f(index1 -1 , index2 , s , t, dp);
        }else{
            return f(index1 -1 , index2 , s , t, dp);
        }
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size() , vector<int>(t.size() , -1));
        return f(s.size()-1 , t.size()-1 , s , t , dp);
    }

    Time Complexity -> O(N*M)
    Space Complexity -> O(N*M)

// Tabulation
Time Complexity -> O(N*M)
Space Complexity -> O(N*M)

    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(s.size()+1 , vector<long long>(t.size()+1 , 0));
        for(int j = 0; j<= s.size() ; j++){
            dp[j][0] = 1;
        }
        for(int i = 1 ;i<=s.size() ; i++){
            for(int j = 1 ;j<=t.size() ; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%1000000007;
                }else{
                    dp[i][j] =  (dp[i-1][j])%1000000007;
                }
            }
        }
        return (int)dp[s.size()][t.size()];
    }

// Space Optimization

// Time Complexity -> O(N*M)
// Space Complexity -> O(N)

    int numDistinct(string s, string t) {
        vector<int> pre(t.size() +1 , 0);
        vector<int> temp(t.size() +1 , 0);
        pre[0] = 1;
        temp[0] = 1;
        for(int i = 1 ; i<=s.size() ; i++){
            for(int j = 1 ; j<=t.size() ; j++){
                long long int result = 0;
                if(s[i-1] == t[j-1]){
                    result = (pre[j-1] + pre[j])%1000000007;
                }else{
                    result = (pre[j])%1000000007;
                }
                temp[j] =  result;
            }
            pre = temp;
        }
        return pre[t.size()];
    }