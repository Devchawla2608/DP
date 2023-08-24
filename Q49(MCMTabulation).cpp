// Matrix Chain Multiplication     

// Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.
// The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

// Link -> https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

// Intution -> While Writing the tabulation just write in opposite fashion I did a mistake and 
// wrote i = 0;i<N but we know that we have to write in opposite fashion

// And We know that j is present in right of i always so 

int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N , vector<int>(N , 0));
        for(int i = N-1;i>=1 ; i--){
            for(int j = i+1 ;j<N ; j++){
                if(i == j){ dp[i][j] = 0; continue;}
                int mn = 1e9;
                for(int k = i ; k<j ; k++){
                    int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                    mn = min(steps , mn);
                }
                dp[i][j] = mn;
            }
        }
        return dp[1][N-1];
    }