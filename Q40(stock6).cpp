    

// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again). 

// Link -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

// Intution -> There is a slight change in this question just added a transaction fee we will - the trasaction fee when we buy or sell 

//     int maxProfit(vector<int>& prices , int fee) {
    //     vector<vector<int>> dp(prices.size() , vector<int>(2 , 0));
    //     dp[prices.size()-1][0] = 0;
    //     dp[prices.size()-1][1] = prices[prices.size()-1];
    //     for(int i = prices.size()-2 ; i>=0 ; i--){
    //         for(int j = 0 ; j<=1 ;  j++){
    //             int profit = 0;
    //             if(j == 0){
    //                 int notBuy = dp[i+1][j];
    //                 int buy =  dp[i+1][j+1] - prices[i] - fee;
    //                 profit = max(notBuy , buy);
    //             }else{
    //                 int notSell = dp[i+1][j];
    //                 int sell =  dp[i+1][j-1] + prices[i];
    //                 profit = max(notSell , sell);
    //             }
    //     dp[i][j] = profit;
    //         }
    //     }
    //     return dp[0][0];
    // }

// Here Fee Is Important 