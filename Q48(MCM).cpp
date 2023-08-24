

// Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.
// The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

// Link -> https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

int f(int i , int j , int arr[] , vector<vector<int>> &dp){
        if(i == j) return 0;
        int mn = 1e9;
        if(dp[i][j] != -1) return dp;
        for(int k = i ; k<j ; k++){
            int steps = arr[i-1]*arr[k]*arr[j] + f(i , k ,arr , dp) + f(k+1 , j , arr , dp);
            mn = min(steps , mn);
        }
        return dp[i][j] =  mn;
    }

    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N , vector<int>(N , -1));
        return f(1 , N-1 , arr , dp);
    }    

// Time Complexity -> Kind of exponential 
// Space Complexity -> O(N)

int f(int i , int j , int arr[] , vector<vector<int>> &dp){
        if(i == j) return 0;
        int mn = 1e9;
        if(dp[i][j] != -1) return dp;
        for(int k = i ; k<j ; k++){
            int steps = arr[i-1]*arr[k]*arr[j] + f(i , k ,arr , dp) + f(k+1 , j , arr , dp);
            mn = min(steps , mn);
        }
        return dp[i][j] =  mn;
    }

    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N , vector<int>(N , -1));
        return f(1 , N-1 , arr , dp);
    }

// Time Complexity -> O(N^3)
// Space Complexity -> O(N^2) + O(N)