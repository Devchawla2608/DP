
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
// Find and return the maximum profit you can achieve.

// Link ->https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// Wr can buy as many times we want 

// ******************* Recursion *******************


    // Time Complexity = o(2*n);
    // Space Complexity = o(n);

    int f(int index , int tell ,vector<int> &arr){
        if(index == arr.size()) return 0;
        int profit = 0;
        if(tell == false){
            int notBuy = f(index+1 , tell  , arr);
            int buy =  f(index+1 , 1  , arr) - arr[index];
            profit = max(notBuy , buy);
        }else{
            int notSell = f(index+1 , tell  , arr);
            int sell =  f(index+1 , 0 , arr) + arr[index] ;
            profit = max(notSell , sell);
        }
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        return f(0 , 0, prices);
    }

// ******************* Memoization *******************

    // Time Complexity = o(n*2);
    // Space Complexity = o(n*2) + o(n);

    int f(int index , int tell ,vector<int> &arr , vector<vector<int>> &dp){
        if(index == arr.size()) return 0;
        int profit = 0;
        if(dp[index][tell] != -1) return dp[index][tell];
        if(tell == false){
            int notBuy = f(index+1 , tell  , arr , dp);
            int buy =  f(index+1 , 1  , arr , dp) - arr[index];
            profit = max(notBuy , buy);
        }else{
            int notSell = f(index+1 , tell  , arr , dp);
            int sell =  f(index+1 , 0 , arr , dp) + arr[index] ;
            profit = max(notSell , sell);
        }
        return dp[index][tell] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() , vector<int>(2 , -1));
        return f(0 , 0, prices , dp);
    }


// ******************** Tabulation ****************

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1 , vector<int>(2 , 0));
        for(int i = prices.size()-1 ; i>=0 ; i--){
            for(int j = 0 ; j<=1 ;  j++){
                int profit = 0;
                if(j == 0){
                    int notBuy = dp[i+1][j];
                    int buy =  dp[i+1][j+1] - prices[i];
                    profit = max(notBuy , buy);
                }else{
                    int notSell = dp[i+1][j];
                    int sell =  dp[i+1][j-1] + prices[i];
                    profit = max(notSell , sell);
                }
        dp[i][j] = profit;
            }
        }
        return dp[0][0];
    }


// ******************** Space Optimized ****************

    int maxProfit(vector<int>& prices) {
        vector<int> after(2 , 0);
        vector<int> temp(2 , 0);
        for(int i = prices.size()-1 ; i>=0 ; i--){
            for(int j = 0 ; j<=1 ;  j++){
                int profit = 0;
                if(j == 0){
                    int notBuy =  after[j];
                    int buy =  after[j+1] - prices[i];
                    profit = max(notBuy , buy);
                }else{
                    int notSell = after[j];
                    int sell =  after[j-1] + prices[i];
                    profit = max(notSell , sell);
                }
        temp[j] = profit;
            }
            after = temp;
        }
        return after[0];
    }