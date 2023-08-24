// Knapsack with Duplicate Items

// Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
// The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
// Note: Each item can be taken any number of times. 

// Link -> https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

    // Recursion 
    int solve(int index , int& weight , int val[] , int wt[]){
        if(index == 0){
            if(weight >= wt[0]){
                int result = val[0]*(weight/wt[0]);
                return result;
            }else{
                return 0;
            }
        }
        if(dp[index][weight] != -1) return dp[index][weight];
        int notTake = solve(index -1 , weight , val , wt );
        int Take = 0;
        if(weight >= wt[index]){
            int a = weight - wt[index];
            Take = val[index] +  solve(index , a  , val , wt );
        }
        return max(notTake , Take);
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        return solve(N-1 , W , val , wt );
    }

    Time Complexity - O(2^n)
    Space Complexity - O(n)


// Memoization

    int solve(int index , int& weight , int val[] , int wt[] , vector<vector<int>> &dp){
        if(index == 0){
            if(weight >= wt[0]){
                int result = val[0]*(weight/wt[0]);
                return result;
            }else{
                return 0;
            }
        }
        if(dp[index][weight] != -1) return dp[index][weight];
        int notTake = solve(index -1 , weight , val , wt , dp);
        int Take = 0;
        if(weight >= wt[index]){
            int a = weight - wt[index];
            Take = val[index] +  solve(index , a  , val , wt  ,dp);
        }
        return dp[index][weight] =  max(notTake , Take);
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N , vector<int>(W +1 , -1));
        return solve(N-1 , W , val , wt , dp);
    }

    Time Complexity - O(N*W)
    Space Complexity - O(N*W) + O(N)


// Tabulation

    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N , vector<int>(W +1 , -1));
        for(int j = 0 ;j< W+1 ; j++){
            if(j >= wt[0]){
                int result = val[0]*(j/wt[0]);
                dp[0][j] =  result;
            }
            else dp[0][j] =  0;
        }
        for(int i = 1 ;i< N; i++){
            for(int j = 0 ;j<=W ; j++){
               int notTake = dp[i-1][j];
                int Take = 0;
                if(j >= wt[i]){
                    int a = j - wt[i];
                    Take = val[i] +  dp[i][j-wt[i]];
                }
                dp[i][j] =  max(notTake , Take); 
            }
        }
        return dp[N-1][W];
    }

    Time Complexity - O(N*W)
    Space Complexity - O(N*W)


// Space Optimization 

int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> pre(W+1 , 0);
        vector<int> temp(W+1 , 0);
        for(int j = 0 ;j< W+1 ; j++){
            if(j >= wt[0]){
                int result = val[0]*(j/wt[0]);
                pre[j] =  result;
            }
            else pre[j] =  0;
        }
        for(int i = 1 ;i< N; i++){
            for(int j = 0 ;j<=W ; j++){
               int notTake = pre[j];
                int Take = 0;
                if(j >= wt[i]){
                    int a = j - wt[i];
                    Take = val[i] +  temp[j-wt[i]];
                }
                temp[j] =  max(notTake , Take); 
            }
            pre = temp;
        }
        return pre[W];
    }

    Time Complexity - O(N*W)
    Space Complexity - O(W)