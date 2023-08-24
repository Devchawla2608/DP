// Partitions with Given Difference

// Given an array arr, partition it into two subsets(possibly empty) such that their union is the original array. Let the sum of the element of these two subsets be S1 and S2. 
// Given a difference d, count the number of partitions in which S1 is greater than or equal to S2 and the difference S1 and S2 is equal to d. since the answer may be large return it modulo 109 + 7.

// Recursion + Memoization
// Time Complexity -> O(2**N)
// Space Complexity -> O(N);


    int f(int index , int sum , int arr[] , vector<vector<int>> &dp){
	    if(index == 0){
	        if(sum == 0 && arr[index] == 0) return 2;
	        else if(sum == 0 && arr[index] != 0) return 1;
            else if(arr[index] == sum) return 1;
	        else return 0;
	    }
	    if(dp[index][sum] != -1) return dp[index][sum];
	    int pick = 0;
	    if(arr[index] <= sum) pick = f(index-1 , sum - arr[index] , arr , dp);
	    int notPick = f(index-1 , sum , arr , dp);
	     return dp[index][sum] = (pick + notPick)%1000000007;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n , vector<int>(sum + 1 , -1));
        return f(n-1 , sum , arr , dp);
	}
  
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = 0;
        for(int i = 0;i<arr.size() ; i++){
            sum += arr[i];
        }
        sum -= d;
        if(sum %2 != 0) return 0;
        int k = sum/2 + d;
        int a[arr.size()];
        for(int i = 0;i<arr.size() ; i++){
            a[i] = arr[i];
        }
        int ans = perfectSum(a , n , k);
        return ans;
    }