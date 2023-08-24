    
// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
// A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

// Link -> https://leetcode.com/problems/shortest-common-supersequence/description/

// Intution -> Intution is very simple In this we are trying to find the shortest supersequence supersequence contains both the sequence
// now we will stay the same portion same and use the dp matrix of lis . See The code 

string shortestCommonSupersequence(string str1, string str2) {

        vector<vector<int>> dp(str1.size()+1 , vector<int>(str2.size()+1 , 0));
        for(int i = 1 ; i<=str1.size() ; i++){
            for(int j = 1 ; j<=str2.size() ; j++){
                int result = 0;
                if(str1[i-1] == str2[j-1]){
                    result = 1 + dp[i-1][j-1];
                }else{
                    result = max(dp[i-1][j] , dp[i][j-1]);
                }
                dp[i][j] = result;
            }
        }
        int row = str1.size();
        int col = str2.size();
        string ans = "";
        while(row > 0 && col >0){
            if(str1[row-1] == str2[col-1]){
                ans += str1[row-1];
                row = row-1;
                col = col-1;
            }else{
                if(dp[row][col-1] > dp[row-1][col]) {
                    ans += str2[col-1];
                    col = col-1;
                }else{
                    ans += str1[row-1];
                    row = row-1;
                }
            }
        }
        while(row > 0){
            ans += str1[row-1];     
            row = row-1;       
        }
        while(col > 0){
            ans += str2[col-1]; 
            col = col-1;            
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }