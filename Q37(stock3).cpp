// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete at most two transactions.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Link -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

// Intution -> Here it is same as the prev question but slightly change here we can not do transactions more than 2 so here we have to maintain third variable which tells us that how many transaction we can do and Important thing is that the transaction will complete when we sell the stock 

// ******************** Recursion ***********************

//     int f(int index , int tell ,vector<int> &arr , int &count , vector<vector<vector<int>>> &dp ){
//         if(count == 0 || index == arr.size()) return 0;
//         int profit = 0;
//         if(tell == 0){
//             int notBuy = f(index+1 , 0 , arr , count, dp);
//             int buy =  f(index+1 , 1  , arr , count , dp) - arr[index];
//             profit = max(notBuy , buy);
//         }else{
//             int notSell = f(index+1 , 1  , arr , count , dp);
//             int a = count-1;
//             int sell =  f(index+1 , 0  , arr , a , dp) + arr[index];
//             profit = max(notSell , sell);
//         }
//         return profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         int count = 2;
//         return f(0 , false , prices ,count , dp );
//     }

Time complexity -> O(2^N);
Space Complexity -> O(N);

// // ******************** Memoization ***********************

//     int f(int index , int tell ,vector<int> &arr , int &count , vector<vector<vector<int>>> &dp ){
//         if(count == 0 || index == arr.size()) return 0;
//         if(dp[index][tell][count] != -1) return dp[index][tell][count];
//         int profit = INT_MIN;
//         if(tell == 0){
//             int notBuy = f(index+1 , 0 , arr , count, dp);
//             int buy =  f(index+1 , 1  , arr , count , dp) - arr[index];
//             profit = max(notBuy , buy);
//         }else{
//             int notSell = f(index+1 , 1  , arr , count , dp);
//             int a = count-1;
//             int sell =  f(index+1 , 0  , arr , a , dp) + arr[index];
//             profit = max(notSell , sell);
//         }
//         return dp[index][tell][count] = profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         int count = 2;
//         vector<vector<vector<int>>> dp(prices.size() , vector<vector<int>>(2 , vector<int>(count+1 , -1)));
//         return f(0 , false , prices ,count , dp );
//     }




//  ***************** Tabulation **********

    // int maxProfit(vector<int>& arr) {
    //     int count = 2;
    //     vector<vector<vector<int>>> dp(arr.size()+1 , vector<vector<int>>(2 , vector<int>(count+1 , 0)));
    //     for(int i = arr.size() -1 ; i>=0 ; i--){
    //         for(int j = 0 ;j<2 ; j++){
    //             for(int k = 2 ;k>0 ; k--){
    //                 int profit = INT_MIN;
    //                 if(j == 0){
    //                     int notBuy = dp[i+1][j][k];
    //                     int buy = dp[i+1][j+1][k] - arr[i];
    //                     profit = max(notBuy , buy);
    //                 }else{
    //                     int notSell = dp[i+1][j][k];
    //                     int sell =  dp[i+1][j-1][k-1] + arr[i];
    //                     profit = max(notSell , sell);
    //                 }
    //                 dp[i][j][k] = profit;
    //                 }
    //             }
    //         }

    //     return dp[0][0][2];
    // }





//  ***************** Space Optimization **********

    // int maxProfit(vector<int>& arr) {
    //     int count = 2;
    //     // vector<vector<vector<int>>> dp(arr.size()+1 , vector<vector<int>>(2 , vector<int>(count+1 , 0)));

    //     vector<vector<int>> after(2 , vector<int>(3 , 0));
    //     vector<vector<int>> temp(2 , vector<int>(3 , 0));
    //     for(int i = arr.size() -1 ; i>=0 ; i--){
    //         for(int j = 0 ;j<2 ; j++){
    //             for(int k = 2 ;k>0 ; k--){
    //                 int profit = INT_MIN;
    //                 if(j == 0){
    //                     int notBuy = after[j][k];
    //                     int buy = after[j+1][k] - arr[i];
    //                     profit = max(notBuy , buy);
    //                 }else{
    //                     int notSell = after[j][k];
    //                     int sell =  after[j-1][k-1] + arr[i];
    //                     profit = max(notSell , sell);
    //                 }
    //                 temp[j][k] = profit;
    //                 }
    //             }
    //             after = temp;
    //         }

    //     return after[0][2];
    // }


// ******************* Way New *************************

    // int f(int index  ,vector<int> &arr  , int &tno , vector<vector<int>> &dp){
    //     if(index == arr.size() || tno == 4) return 0;
    //     int profit = INT_MIN;
    //     if(dp[index][tno] != -1) return dp[index][tno];
    //     if(tno%2 == 0){
    //         int notBuy = f(index+1 , arr , tno , dp );
    //         int a = tno+1;
    //         int buy =  f(index+1   , arr , a , dp ) - arr[index];
    //         profit = max(notBuy , buy);
    //     }else{
    //         int notSell = f(index+1 , arr , tno , dp );
    //         int a = tno+1;
    //         int sell =  f(index+1  , arr ,a , dp ) + arr[index];
    //         profit = max(notSell , sell);
    //     }
    //     return dp[index][tno] = profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int tno = 0;
    //     vector<int> after(5 , 0);
    //     vector<int> temp(5 , 0);
    //     for(int i = prices.size() -1 ; i>=0 ; i--){
    //         for(int j =3 ; j>= 0 ; j--){
    //             int profit = INT_MIN;
    //             if(j%2 == 0){
    //                 int notBuy = after[j];
    //                 int buy =  after[j+1] - prices[i];
    //                 profit = max(notBuy , buy);
    //             }else{
    //                 int notSell = after[j];
    //                 int sell = after[j+1]  + prices[i];
    //                 profit = max(notSell , sell);
    //             }
    //         temp[j] = profit;
    //         }
    //         after = temp;
    //     }
    //     return after[0];
    // }