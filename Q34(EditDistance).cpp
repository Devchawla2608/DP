// Edit Distance

// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

// Recursion
    int f(int index1 , int index2 , string word1 , string word2  ){
        if(index1 < 0) return index2 + 1;
        if(index2 < 0) return index1 + 1;
        if(word1[index1] == word2[index2]) return f(index1-1 , index2-1 , word1 , word2 );
        return min(f(index1 , index2-1 , word1 , word2 ) ,min( f(index1 -1 , index2 , word1 , word2 ) , f(index1-1 , index2 -1 , word1 , word2 )))+1;
    }

    int minDistance(string word1, string word2) {
        return f(word1.size() -1 , word2.size() -1 , word1 , word2 );
    }

    // Time Complexity -> O(3^N)
    // Space Complexity -> O(N)


// Memoization

    int f(int index1 , int index2 , string word1 , string word2 , vector<vector<int>> &dp){
        if(index1 < 0) return index2 + 1;
        if(index2 < 0) return index1 + 1;
        if(dp[index1][index2] != -1) return dp[index1][index2];
        if(word1[index1] == word2[index2]) return f(index1-1 , index2-1 , word1 , word2, dp);
        return dp[index1][index2] = min(f(index1 , index2-1 , word1 , word2, dp) ,min( f(index1 -1 , index2 , word1 , word2, dp) , f(index1-1 , index2 -1 , word1 , word2, dp)))+1;
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() , vector<int>(word2.size() , -1));
        return f(word1.size() -1 , word2.size() -1 , word1 , word2 , dp);
    }

    Time Complexity -> O(N*M)
    Space Complexity -> O(N*M)

    // Tabulation

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1 , vector<int>(word2.size()+1 , 0));
        for(int i = 0 ;i<=word1.size() ; i++){
            dp[i][0] = i;
        }
        for(int i = 0 ;i<=word2.size() ; i++){
            dp[0][i] = i;
        }
        for(int i = 1 ;i<=word1.size() ; i++){
            for(int j = 1 ;j<=word2.size() ; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1+ min(dp[i-1][j-1] , min(dp[i-1][j] , dp[i][j-1]));
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }

    Time Complexity -> O(N*M)
    Space Complexity -> O(N*M)


    // Space Optimization

    int minDistance(string word1, string word2) {
        vector<int> after(word2.size()+1 , 0);
        vector<int> temp(word2.size()+1 , 0);
        for(int i = 0 ;i<=word2.size() ; i++){
            after[i] = i;
        }
        for(int i = 1 ;i<=word1.size() ; i++){
            for(int j = 0 ;j<=word2.size() ; j++){
                if(j == 0){
                    temp[j] = i;
                }else{
                    if(word1[i-1] == word2[j-1]){
                        temp[j] = after[j-1];
                    }else{
                        temp[j] = 1+ min(after[j-1] , min(after[j] , temp[j-1]));
                    }
                }
            }
            after = temp;
        }
        return after[word2.size()];
    }