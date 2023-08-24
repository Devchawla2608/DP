// Ninja Training
// Ninja is planing this 'N' days-long training schedule. Each day, he
// can perform any one of these three activities. (Running, Fighting
// Practice or Learning New Moves). Each activity has some merit
// points on each day. As Ninja has to improve all his skills, he can't
// do the same activity in two consecutive days. Can you help Ninja
// find out the maximum merit points Ninja can earn?
// You are given a 2D array of size N*3 'POINTS' with the points
// corresponding to each day and activity. Your task is to calculate
// the maximum number of merit points that Ninia can earn.

// Coding Ninjas link -> https://www.codingninjas.com/codestudio/problems/ninja-training_1171211?leftPanelTab=0

// Recursion O(3**N) O(N);
int f(int i  , vector<vector<int>> &arr , int pre ){
    if(i == 0){
        if(pre == 0) return max(arr[i][1] , arr[i][2]);
        if(pre == 1) return max(arr[i][0] , arr[i][2]);
        if(pre == 2) return max(arr[i][0] , arr[i][1]);
        return max(arr[i][0] , max(arr[i][1] , arr[i][2]));
    }
    int ans = INT_MIN;
    if(pre != 0) ans = max(ans , f(i-1 , arr , 0) + arr[i][0]);
    if(pre != 1) ans = max(ans , f(i-1 , arr , 1)+ arr[i][1]);
    if(pre != 2) ans = max(ans , f(i-1 , arr , 2)+ arr[i][2]);
    return ans;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{   
    return f(n-1 , points , 3);
}

//  Memoization O(N**2)  SC ->O(N**2 + O(N));
int f(int i  , vector<vector<int>> &arr , int pre ,
vector<vector<int>> &dp){
    if(i == 0){
        if(pre == 0) return max(arr[i][1] , arr[i][2]);
        if(pre == 1) return max(arr[i][0] , arr[i][2]);
        if(pre == 2) return max(arr[i][0] , arr[i][1]);
        return max(arr[i][0] , max(arr[i][1] , arr[i][2]));
    }
    if(dp[i][pre] != -1) return dp[i][pre];
    int ans = INT_MIN;
    if(pre != 0) ans = max(ans , f(i-1 , arr , 0 , dp) + arr[i][0]);
    if(pre != 1) ans = max(ans , f(i-1 , arr , 1 , dp)+ arr[i][1]);
    if(pre != 2) ans = max(ans , f(i-1 , arr , 2 , dp)+ arr[i][2]);
    return dp[i][pre] =  ans;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{   
    vector<vector<int>> dp(n , vector<int>(4 , -1));
    return f(n-1 , points , 3 , dp);
}

// Tabulation

int ninjaTraining(int n, vector<vector<int>> &points)
{   
    vector<vector<int>> dp(n+1 , vector<int>(4 , 0));
    for(int i = 1 ;i<=n;i++){
        for(int j = 0 ; j<= 4 ; j++){
            int ans = INT_MIN;
            if(j != 0) ans = max(ans ,dp[i-1][0] + arr[i][0]);
            if(j != 1) ans = max(ans , dp[i-1][1] + arr[i][1]);
            if(j != 2) ans = max(ans , dp[i-1][2] + arr[i][2]);
            dp[i][j] = ans;
        }
    }
    return dp[n][4];
}