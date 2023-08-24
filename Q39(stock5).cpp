
// You are given an array prices where prices[i] is the price of a given stock on the ith day
// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Link -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

//! Intution -> In this we can do as many transactions we want but there is a case is we sell a stock we can not but the stock on next day do we do +2 in selling and have to add one more base case becuase at last day if we do +2 then we will go to n+2 so add one case more 

// ******************* Recursion *******************
    // Time Complexity = o(2*n);
    // Space Complexity = o(n);

    // int f(int index , int tell ,vector<int> &arr){
    //     if(index == arr.size() +1) return 0; 
    //     if(index == arr.size()) return 0;
    //     int profit = 0;
    //     if(tell == false){
    //         int notBuy = f(index+1 , tell  , arr);
    //         int buy =  f(index+1 , 1  , arr) - arr[index];
    //         profit = max(notBuy , buy);
    //     }else{
    //         int notSell = f(index+1 , tell  , arr);
    //         int sell =  f(index+2 , 0 , arr) + arr[index] ;
    //         profit = max(notSell , sell);
    //     }
    //     return profit;
    // }

    // int maxProfit(vector<int>& prices) {
    //     return f(0 , 0, prices);
    // }

// ******************* Memoization *******************

    // Time Complexity = o(n*2);
    // Space Complexity = o(n*2) + o(n);

    // int f(int index , int tell ,vector<int> &arr , vector<vector<int>> &dp){
    //     if(index == arr.size() + 1) return 0;
    //     if(index == arr.size()) return 0;
    //     int profit = 0;
    //     if(dp[index][tell] != -1) return dp[index][tell];
    //     if(tell == false){
    //         int notBuy = f(index+1 , tell  , arr , dp);
    //         int buy =  f(index+1 , 1  , arr , dp) - arr[index];
    //         profit = max(notBuy , buy);
    //     }else{
    //         int notSell = f(index+1 , tell  , arr , dp);
    //         int sell =  f(index+2 , 0 , arr , dp) + arr[index] ;
    //         profit = max(notSell , sell);
    //     }
    //     return dp[index][tell] = profit;
    // }

    // int maxProfit(vector<int>& prices) {
    //     vector<vector<int>> dp(prices.size() , vector<int>(2 , -1));
    //     return f(0 , 0, prices , dp);
    // }


// // ******************** Tabulation ****************

//     int maxProfit(vector<int>& prices) {
//         vector<vector<int>> dp(prices.size()+2 , vector<int>(2 , 0));
//         for(int i = prices.size()-1 ; i>=0 ; i--){
//             for(int j = 0 ; j<=1 ;  j++){
//                 int profit = 0;
//                 if(j == 0){
//                     int notBuy = dp[i+1][j];
//                     int buy =  dp[i+1][j+1] - prices[i];
//                     profit = max(notBuy , buy);
//                 }else{
//                     int notSell = dp[i+1][j];
//                     int sell =  dp[i+2][j-1] + prices[i];
//                     profit = max(notSell , sell);
//                 }
//         dp[i][j] = profit;
//             }
//         }
//         return dp[0][0];
//     }


// ******************** Space Optimized ****************

    // int maxProfit(vector<int>& prices) {
    //     vector<int> afterafter(2 , 0);
    //     vector<int> after(2 , 0);
    //     vector<int> temp(2 , 0);
    //     for(int i = prices.size()-1 ; i>=0 ; i--){
    //         for(int j = 0 ; j<=1 ;  j++){
    //             int profit = 0;
    //             if(j == 0){
    //                 int notBuy =  after[j];
    //                 int buy =  after[j+1] - prices[i];
    //                 profit = max(notBuy , buy);
    //             }else{
    //                 int notSell = after[j];
    //                 int sell =  afterafter[j-1] + prices[i];
    //                 profit = max(notSell , sell);
    //             }
    //     temp[j] = profit;
    //         }
    //         afterafter = after 
    //         after = temp;
    //     }
    //     return after[0];
    // }