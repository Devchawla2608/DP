
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Link -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

//! Intution -> Just little change change 2 with k

// int maxProfit(int k, vector<int>& prices) {
//         if(k == 0) return 0;
//         int tno = 0;
//         vector<int> after(2*k+1 , 0);
//         vector<int> temp( 2*k+1 , 0);
//         for(int i = prices.size() -1 ; i>=0 ; i--){
//             for(int j =2*k-1 ; j>= 0 ; j--){
//                 int profit = INT_MIN;
//                 if(j%2 == 0){
//                     int notBuy = after[j];
//                     int buy =  after[j+1] - prices[i];
//                     profit = max(notBuy , buy);
//                 }else{
//                     int notSell = after[j];
//                     int sell = after[j+1]  + prices[i];
//                     profit = max(notSell , sell);
//                 }
//             temp[j] = profit;
//             }
//             after = temp;
//         }
//         return after[0];
//     }