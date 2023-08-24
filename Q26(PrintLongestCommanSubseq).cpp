
// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

// Link -> https://leetcode.com/problems/longest-common-subsequence/

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

        int len = dp[text1.size()][text2.size()];
        int i = text1.size();
        int j = text2.size();
        string s ="";
        for(int i = 0 ;i< len ; i++){
            string temp = s + '$';
            s = temp;
        }
        int index = len-1;
        while(i>0 && j>0){
            if(text1[i-1] == text2[j-1]){
                s[index] = text1[i-1];
                index--;
                i--;
                j--;
            }else{
                if(dp[i-1][j] > dp[i][j-1]){
                    i--;
                }else{
                    j--;
                }
            }
        }
        cout<<s<<endl;
        return dp[text1.size()][text2.size()];
    }