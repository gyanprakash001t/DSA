#include<bits/stdc++.h>
using namespace std;

// using recursion
int fibonacci(int n)
{
    if(n==0 || n==1)return n;
    return fibonacci(n-1)+fibonacci(n-2);
}

// using DP

// memoization (top-down)
int fibonacciDP(int n, vector<int> &dp)
{
    if(n==0 || n==1)return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fibonacciDP(n-1, dp)+ fibonacciDP(n-2, dp);
}

// tabulation (bottom-up)

int fibonacciDP_tabulation(int n)
{
    vector<int>dp;
    dp[0]=0;
    dp[1]=1;
     
    for(int i=2; i<n; i++)
    {
        dp[i]= dp[i-1] +dp[i-2];
    }
    return dp[n-1];
}

// space optimization on tabulation;

int fib_tabulation_space_optimization(int n )
{
    int prev = 1;
    int prev_1 = 0;
    int curr =0;
    for(int i=2; i<n; i++)
    {
        curr = prev +prev_1;
        prev_1= prev;
        prev= curr;
    }
    return curr;
}


int main()
{
    
    return 0;
}