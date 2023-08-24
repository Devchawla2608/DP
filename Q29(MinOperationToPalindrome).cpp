
// Given a string s. In one step you can insert any character at any index of the string.
// Return the minimum number of steps to make s palindrome.
// A Palindrome String is one that reads the same backward as well as forward.


Link -> https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/ 
// Intution -> We have to find the no of operations from which we can make a string palindrome to do that we will take longest palindrome subsequnce same and and copy the left part because question did not asked about the string so it is easy 
// No Of Operations -> N - lcs 

void reverseStr(string& str, int n, int i)
{
     
  if(n<=i){return;}
//  Swapping the character
  swap(str[i],str[n]);
  reverseStr(str,n-1,i+1);
 
}

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
    int minInsertions(string s) {
        int length = longestPalindromeSubseq(s);
        return s.size()-length;
    }