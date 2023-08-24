// 121. Best Time to Buy and Sell Stock 

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Link -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

    int maxProfit(vector<int>& arr) {
        int mn = arr[0];
        int profit = 0;
        for(int i = 1 ;i<arr.size() ; i++){
            int cost = arr[i] - mn;
            profit = max(profit , cost);
            mn = min(mn , arr[i]);
        }
        return profit;
    }

// Time Complexity -> O(N);
// Space Complexity -> O(1) 