// climbStairs

// There is a frog on the '1st step of an 'N' stairs long staircase. The frog wants to reach the "Nth' stair. "HEIGHT" is the height of the '6+13th' stair.If Frog jumps from "ith' to 'th' stair, the energy lost in the jump is given by absolute value of { HEIGHT-11-HEIGHT-1)). If the Frog is on 'ith' staircase, he can jump either to +1)th' stair or to '(+2)th' stair. Your task is to find the minimum total energy used by the frog to reach from "Ist' stair to "Nth' stair. For Example

Link -> https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

class Solution {
public:

//! Recursion TC[ o(2**N) ] SC[ O(N) ] 
    int f(int index){
        if(index == 0 || index == 1) return 1;
        int left = f(index-1);
        int right = f(index-2);
        return left + right;
    }

    int climbStairs(int n) {
        return f(n);
    }


//! Memoization TC[ o(N) ] SC[ O(N) + O(N) ] 
    int f(int index , vector<int> &dp){
        if(index == 0 || index == 1) return 1;
        if(dp[index] != -1) return dp[index];
        int left = f(index-1 , dp);
        int right = f(index-2 , dp);
        return dp[index] = left + right;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1 , -1);
        return f(n , dp);
    }

//Tabulation TC[ O(N) ] SC[O(N) ] 

    int climbStairs(int n) {
        vector<int> dp(n+1 , -1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2 ; i<= n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }


//Space Opt TC[ O(N) ] SC[O(1)] 

    int climbStairs(int n) {
        int cur = 1;
        int pre = 1;
        int next = 0;
        for(int i = 2 ; i<= n ; i++){
            next = pre + cur;
            pre = cur;
            cur = next;
        }
        return cur;
    }


};