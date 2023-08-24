

// You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
// In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

// Same Intution as of previous question 

// Gfg link -> https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#

// Recursion 
Time Complexity -> O(2**N)
Space Complexity -> O(N*W) + O(N);

int f(int W , int index , int wt[] , int val[]){
        if(W == 0) return 0;
        if(index == 0){
            if(wt[index] <= W){
                W = W-wt[index];
                return val[index];
            }
            return 0;
        }
        
        int notPick = f(W , index-1 , wt, val);
        int pick = 0;
        if(wt[index] <= W){
            pick = f(W- wt[index] , index-1 , wt , val) + val[index];
        }
        return max(notPick , pick);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       return f(W , n-1 , wt ,val);
    }

// Memoization
Time Complexity -> O(N*W)
Space Complexity -> O(N*W) + O(N);

int findWays(vector<int> &arr, int tar)
{   
    vector<int> pre(tar+1 , 0);
    vector<int> temp(tar+1 , 0);
    for(int i =0  ;i<tar+1 ; i++){
        if(i == 0 && arr[0] == 0) pre[0] = 2;
        else if(i == 0 || i == arr[0]) pre[i] = 1;
        else pre[i] = 0;
    }
    for(int i = 1 ;i< arr.size() ; i++){
        for(int j = 0;j<=tar ; j++){
            int notPick = pre[j];
            int pick = 0;
            if(j >= arr[i]) pick = pre[j-arr[i]];
            temp[j] = notPick + pick;   
        }
        pre = temp;
    }
    return pre[tar];
}

// Tabulation 
Time Complexity -> O(N*W)
Space Complexity -> O(N*W) ;
    int knapSack(int W, int wt[], int val[], int n) 
    {   
        vector<vector<int>> dp( n , vector<int>(W+1 , 0));
        for(int i = 0 ; i< n ; i++) dp[i][0] = 0;
        for(int i = 0 ;i<=W ; i++){
            if( i >= wt[0]){
                dp[0][i] = val[0];
            }
        }
        for(int i = 1 ;i<n ; i++){
            for(int j = 1 ; j <=W ; j++){
                int notPick = dp[i-1][j];
                int pick = 0;
                if(wt[i] <= j) pick = dp[i-1][j-wt[i]] + val[i];
                dp[i][j] = max(notPick , pick);
            }
        }
        return dp[n-1][W];
    }

// Space Optimization 

Time Complexity -> O(N*W)
Space Complexity -> O(N) ;

    int knapSack(int W, int wt[], int val[], int n) 
    {   
        vector<int> pre(W+1 , 0);
        vector<int> cur(W+1 , 0);
        pre[0] = 0;
        for(int i = 0 ;i<=W ; i++){
            if( i >= wt[0]){
                pre[i] = val[0];
            }
        }
        for(int i = 1 ;i<n ; i++){
            for(int j = 1 ; j <=W ; j++){
                int notPick = pre[j];
                int pick = 0;
                if(wt[i] <= j) pick = pre[j-wt[i]] + val[i];
                cur[j] = max(notPick , pick);
            }
            pre = cur;
        }
        return pre[W];
    }