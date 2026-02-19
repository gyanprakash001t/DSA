//  find total number of ways to reach to top of a staircase ;
// you have to  move either one or two steps each time 

//since here we are requires to find the total number of ways means you should think of DP

#include<bits/stdc++.h>
using namespace std ;

// recursive solution
int no_of_ways_recursive(int n)
{
    if(n==0) return 1;
   


    int one_step_ways = no_of_ways_recursive(n-1);
    int two_step_ways= 0;
    if(n>1)
    {
         two_step_ways = no_of_ways_recursive(n-2);
    }
    return  (one_step_ways + two_step_ways);

}


// memoization
int no_of_ways_memoization(int n, vector<int>&dp)
{
    if(n==0) return 1;
    if(dp[n] != -1) return dp[n];
    int one_step_ways = no_of_ways_memoization(n-1, dp);
    int two_step_ways= 0;
    if(n>1)
    {
         two_step_ways = no_of_ways_memoization(n-2, dp);
    }

    return dp[n] = (one_step_ways+two_step_ways);


}

// tabulation
// we want to eliminate this array so the the space  complexity reduce to O(n) earlier  it was O(n)  + O(n)  one for  recursion stack  and other for  dp array now if we able to eleiminate recursin calls  

int no_of_ways_tabulation(int n)
{
    vector<int>dp(n+1,0);
    dp[0]=1;
    
    for(int i=1; i<=n; i++)
    {
       int one_step_ways = dp[i-1];
       int two_step_ways= 0;
       if(i>1)
       {
         two_step_ways = dp[i-2];
       }
       dp[i] = (one_step_ways +two_step_ways);
    }
    return dp[n];
}

// optimized_tabulation
// now we want to remove this dp array with three variables  which will makes the space complexity O(1);  the most optimised 
int  no_of_ways_optimized_tabulation(int n)
{
    if(n == 0) return 1;
    if(n == 1) return 1;

    int prev_2 = 1; //dp[0]
    int prev_1 = 1; //dp[1]
   

    for(int i= 2; i<=n; i++)
    {
       int curr = prev_2 + prev_1;
       prev_2 = prev_1;
       prev_1 =curr;
      
    }
    return prev_1;
}

int main()
{
    int n = 3;
    vector<int>dp(n+1, -1);
    cout<<no_of_ways_recursive(n)<<endl;
    cout<<no_of_ways_memoization(n,dp)<<endl;
    cout<<no_of_ways_tabulation(n)<<endl;
    // cout<<no_of_ways_optimized_tabulation<<endl;
    cout<<no_of_ways_optimized_tabulation(n);


    return 0;
}