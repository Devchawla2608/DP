// ! Tabulation

// Here in the intution we are using the concept of longest comman subsequence in which we just
// But in this we do not carry the previous so a slight change in code  like this 

// if(match){
// dp[i][j] = dp[i-1][j-1] +1;
// }else {
// dp[i][j] = 0;
// }

#include <bits/stdc++.h> 
int lcs(string &str1, string &str2){
	vector<vector<int>> dp(str1.size()+1 , vector<int>(str2.size() + 1 , 0));
int maxElement = INT_MIN;
	for(int i = 1 ;i<= str1.size() ; i++){
		for(int j  = 1 ; j<=str2.size() ; j++){
			if(str1[i-1] == str2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
                 maxElement = max(maxElement , dp[i][j]);
			}
		}
	}
	return maxElement;
}

// Same Time Complexity and space complexity 