// 494. Target Sum

// You are given an integer array nums and an integer target.
// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.


// Leetcode Link -> https://leetcode.com/problems/target-sum/description/

    int solve(int index , int target , int sum , vector<int> &arr){
        if(index == 0){
            int plus = 0;
            int minus = 0;
            if(sum+arr[0] == target) plus =  1;
            if(sum - arr[0] == target) minus =  1;
            return plus + minus;
        }
        int plus = solve(index-1 , target , sum + arr[index] , arr);
        if(index == arr.size()-1) cout<<plus<<endl;
        int minus = solve(index-1 , target , sum - arr[index] , arr);
        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(n-1 , target , 0 , nums);
    }

// Time complexity - O(2^n)
// Space complexity - O(n)