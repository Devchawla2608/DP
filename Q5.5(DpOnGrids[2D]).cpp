// Here we are going to learn 2D dp or dp on matrix 
// There will be 6 types of questions 
// 1.) Count Paths
// 2.) Count Paths with obstacles
// 3.) Min path Sum
// 4.) Max Path sum
// 5.) Triangle
// 6.) Multiple Start Points

//! Try all path Recursion 

// Steps For 2D grid 
// 1.)Express in terms of index i  j
// 2.) Explore and do all the stuff
// 3.) Sum up all ways / max / min 

// F(i , j) -> Give me all ways 

//todo Pseduo Code 
f(i , j){
    if(i == 0 && j == 0) return 1;
    if(i <0 || j < 0) return 0;
    // Step 1 is done
    int up = f(i-1 , j);
    int left = f(i , j-1);
    return up + left;
}

// Time Complexity -> O(2**N*M) There are n*m cells and we are doing 2 calls
// Space Complexity -> O(M-1) + O(N-1)

//! If there are over lapping sub problems we have to do memoization 

// Rules For memoization
// 1.) Find Changing parameter and in this case i , j 
// 2.) Find max value of i and j and according to that create the dp array dp[m][n]
2.) Stores the value you are returing 
// 3.) if(dp[i][j] != -1) return dp[i][j]  

//! Time Complexity -> O(M*N)
//! Space Complexity -> O(M+N) + O(M*N)


// Tabulation  
// Time Complexity ->O(M*N) 
// Space Complexity -> O(M*N) 
Memo -> Tabulation
1.) define base case
2.) Express all the states in for loop
3.) Copy the recurrsion and write

// Space Optimization 
// We are using only two rows so we will not use dp array only use 2 1d array/