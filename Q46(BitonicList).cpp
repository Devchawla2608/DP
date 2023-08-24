// Longest Bitonic subsequence

// Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
// A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing.

class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
        vector<int> dp1(nums.size() , 1);
        vector<int> dp2(nums.size() , 1);
        int front = 1;
        int back = 1;
        for(int i = 0 ;i<nums.size() ; i++){
            for(int j = 0 ;j<i ; j++){
                if(nums[i] > nums[j]){
                    dp1[i] = max(dp1[i] , dp1[j]+1);
                    front = max(front , dp1[i]);
                }
            }
        }
        
        for(int i = nums.size()-1 ;i>=0 ; i--){
            for(int j = i+1 ;j<nums.size() ; j++){
                if(nums[i] > nums[j]){
                    dp2[i] = max(dp2[i] , dp2[j]+1);
                    back = max(back , dp2[i]);
                }
            }
        }
        int sum = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            if(dp1[i] + dp2[i] > sum){
                sum = dp1[i] + dp2[i];
            }
        }
        return sum  -1;
	}
};

// Time Complexity: O(n^2)
// Space Complexity: O(n)