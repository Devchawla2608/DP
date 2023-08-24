	
// Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another 
point.

// Link -> https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

// Intution -> In this question we want to change str1 to str2 and there are two operations allowed we can do delete and insert we will find longest comman subsequence and then find the differenct element in both string and the result = diffInSting1 + diffInString2 

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
	
	int minOperations(string str1, string str2) 
	{ 
        int len = longestCommonSubsequence(str1 , str2);
        int len1 = str1.size();
        int len2 = str2.size();
        len1 = len1 - len;
        len2 = len2 - len;
        return len1 + len2;
	} 