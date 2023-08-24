// Online C++ compiler to run C++ program online
#include <iostream
using namespace std;

// Brute Force 

int fibo(int n){
    if(n<=1){
        return n;
    }
    int a = fibo(n - 1);
    int b = fibo(n-2);
    return a+b;
}

//Memoization (To Down Approach) This will mostly recursive 

int fibo_helper(int n , int* arr){
    if(n<=1){
        return n;
    }
    if(arr[n] != -1){
        return arr[n];
    }
    int a = fibo_helper(n - 1);
    int b = fibo_helper(n-2);
    ans[n] = a+b;
    return ans[n];
}

// Dynamic Programming(bottom up) This will mostly iteratively 

int fibo_2(int n){
    if(n<=1){
        return n;
    }
    int *arr = new int[n]+1;
    for(int i = 0 ;i<n ; i++){
        arr[i] = -1;
    }
    return fibo_helper(n , arr);
}

int fibo_iterately_helper(int n , int *arr){
    int i = 0;
    while(i+2<=n){
        arr[i+2] = arr[i] + arr[i+1];
    }
    return arr[n];
}

int fibo_iterately(int n){
     if(n<=1){
        return n;
    }
    int *arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;
    return fibo_iterately_helper(n , arr);
}

// We will Follow this approach like
// 1.) Brute Force
// 2.) Memoization
// 3.) Dynamic Programming 


int main() {
  

    return 0;
}