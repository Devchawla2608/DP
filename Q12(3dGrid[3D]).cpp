// 3d 
// Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains
// some chocolates. Ninja has two friends Alice and Bob, and he
// wants to collect as many chocolates as possible with the help of
// his friends.
// Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the
// top-right place i.e. (0, 'C' - 1) in the grid. Each of them can move
// from their current cell to the cells just below them. When anyone
// passes from any cell, he will pick all chocolates in it, and then the
// number of chocolates in that cell will become zero. If both stay in
// the same cell, only one of them will pick the chocolates in it.
// If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1)
// or (i + 1, j + 1). They will always stay inside the 'GRID'
// Your task is to find the maximum number of chocolates Ninja can
// collect with the helo of his friends by following the above rules.

#include <bits/stdc++.h> 

int solve(int io  , int j1 , int j2 , vector<vector<int>> &arr , int r ,int c , vector<vector<vector<int>>> &dp){
    if(j1<0 || j1 >c-1 || j2<0 || j2> c-1){
        return  0;
    }

    if(io == r-1){
        if(j1 == j2) return arr[io][j1];
        else return arr[io][j1] + arr[io][j2];
    }

    if(dp[io][j1][j2] != 1) return dp[io][j1][j2];  

    int maxi = 0;
    for(int i = -1 ; i<2 ; i++){
        for(int j = -1 ; j<2 ; j++){
            maxi = max(maxi , solve(io+1 , j1+i , j2+j , arr , r , c , dp));
        }
    }
    int value = 0;
    if(j1 == j2) value = arr[io][j1];
    else value = arr[io][j1] + arr[io][j2];
    return dp[io][j1][j2] = maxi + value ;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r , vector<vector<int>>(c , vector<int>(c , 1)));
    return solve(0 , 0 , c-1 , grid , r ,c , dp);
}
// Time Complexity -> O(r*c*c)
// Space Complexity -> O(r*c*c)