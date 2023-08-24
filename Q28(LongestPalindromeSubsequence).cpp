// Given a string s, find the longest palindromic subsequence's length in s.
// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

// Link -> https://leetcode.com/problems/longest-palindromic-subsequence/description/

// Intution -> In this question We have to find longest palindrome subsequence so it means reverse the string s and find longest comman palindrome subsequence 

//  ! longestCommonSubsequence + longestPalindromeSubseq

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


    int longestPalindromeSubseq(string s) {
        string p = s;
        reverseStr(p, p.length()-1, 0);
        return longestCommonSubsequence(s , p);
    }

    // Time Complexity -> O(n^2)
    // Space Complexity -> O(n^2)