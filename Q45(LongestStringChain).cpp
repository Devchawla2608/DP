// longes string chain 
// You are given an array of words where each word consists of lowercase English letters.

// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

// Return the length of the longest possible word chain with words chosen from the given list of words.

// Link -> https://leetcode.com/problems/longest-string-chain/

bool hasSubsequence(string s1 , string s2){
        int j = 0;
        for(int i = 0 ;i< s1.size() ; i++){
            if(s1[i] == s2[j]) j++;
            if(j == s2.size()) return true;
        }
        if(j == s2.size()) return true;
        else return false;
    }

    static bool cmp(string s1 , string s2){
        return s1.size() < s2.size();
    }


    int longestStrChain(vector<string>& words) {

        // Here we created dp because we are storing the length of longest  Other algo of LIS 
        vector<int> dp(words.size() , 1);
        sort(words.begin() , words.end() , cmp);
// Sort becuase we are doing on subsequence not subset so we pick random in a correct way 
        int mxln = 1;
        for(int i = 0 ;i< words.size() ; i++){
            for(int j = 0 ; j< i ; j++){
                if(words[i].size() - words[j].size() == 1){
                    // Has subsequence will check whether words[i] can be predeccor of words[j]
                    bool get = hasSubsequence(words[i] ,words[j]);
                    if(get == true){
                        // If true then we will update the dp[i]
// ans mxln 
                        dp[i] = max(dp[i] , dp[j]+1);
                        mxln = max(mxln , dp[i]);
                    }
                }
            }
        }
        return mxln;
    }

    // Time Complexity: O(N^2 * M)
    // Space Complexity: O(N)