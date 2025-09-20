#include<bits/stdc++.h>
using namespace std;

// using recursion
int fibonacci(int n)
{
    if(n==0 || n==1)return n;
    return fibonacci(n-1)+fibonacci(n-2);
}

// using DP
int fibonacciDP(int n, vector<int> &dp)
{
    if(n==0 || n==1)return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fibonacciDP(n-1, dp)+ fibonacciDP(n-2, dp);
}
