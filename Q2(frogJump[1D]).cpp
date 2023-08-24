
//There is a frog on the 1st step of an 'N' stairs long staircase. The frog wants to reach the "Nith' stair. "HEIGHT" is the height of the (i+1)th' stair.If Frog jumps from "th' to "th' stair, the energy lost in the jump is given by absolute value of ( HEIGHT-1)-HEIGHT-13). If the Frog is on th' staircase, he can jump either to 6+1)th' stair or to '(+2)th' stair. Your task is to find the minimum total energy used by the frog to reach from '1st stair to "Nth' stair.

// Link -> https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


// Intution -> In this questionwe are standing on Nth stair and we want to go to 0th so we will apply dp see the code 

//  Recursion O(2**N) O(N)
int f(int index , vector<int> &arr){
    if(index == 0) return 0;
    if(index == 1) return abs(arr[0] - arr[1]);
    int left = f(index-1 , arr) + abs(arr[index] - arr[index-1]);
    int right = f(index-2 , arr)+ abs(arr[index] - arr[index-2]);
    return min(left , right);
}

int frogJump(int n, vector<int> &arr)
{
    return f(n-1 , arr);
}

//  Memoization  O(N) + O(N + N )
int f(int index , vector<int> &arr , vector<int> &dp){
    if(index == 0) return 0;
    if(index == 1) return abs(arr[0] - arr[1]);
    if(dp[index] != -1) return dp[index];
    int left = f(index-1 , arr , dp) + abs(arr[index] - arr[index-1]);
    int right = f(index-2 , arr , dp)+ abs(arr[index] - arr[index-2]);
    return dp[index] = min(left , right);
}

int frogJump(int n, vector<int> &arr)
{   
    vector<int> dp(n , -1);
    return f(n-1 , arr , dp);
}

//  Tabulation O(N) + o(N)
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &arr)
{
    vector<int> dp(n , -1);
    dp[0] = 0;
    dp[1] = abs(arr[0] - arr[1]);
    for(int i = 2 ; i<n ; i++){
        int left = dp[i-1] + abs(arr[i] - arr[i-1]);
        int right = dp[i-2] + abs(arr[i] - arr[i-2]);
        dp[i] = min(left , right);
    }
    return dp[n-1];
}

//  Space Opt O(N) + O(1)
int frogJump(int n, vector<int> &arr)
{
    vector<int> dp(n , -1);
    int pre = 0;
    int curr = abs(arr[0] - arr[1]);
    int next = 0;
    for(int i = 2 ; i<n ; i++){
        next = min(pre + abs(arr[i] - arr[i-2]) , 
        curr + abs(arr[i] - arr[i-1]));
        pre = curr;
        curr = next;
    }
    return curr;
}