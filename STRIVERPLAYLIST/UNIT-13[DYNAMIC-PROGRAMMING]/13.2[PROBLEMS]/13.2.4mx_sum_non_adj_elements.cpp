// given with array of integers and need to return maximum sum no of subsequence with constraint no two elements are adjacent in the given array


#include<bits/stdc++.h>
using namespace std;

// recursive method 

int max_non_adj_subseq_sum(vector<int>&arr, int idx)
{
    if(idx == 0) return arr[idx];
    if(idx < 0) return 0;

    int pick_curr_to_the_subseq = max_non_adj_subseq_sum(arr, idx-2) + arr[idx];
    int not_picking_curr_to_the_subseq = max_non_adj_subseq_sum(arr, idx-1) ;

    return max(pick_curr_to_the_subseq, not_picking_curr_to_the_subseq );
}


// memoization

int max_non_adj_subseq_sum_memoization(vector<int>&arr, int idx, vector<int>&dp)
{
    if(idx == 0) return arr[idx];
    if(idx < 0) return 0;

    if(dp[idx] != -1) return dp[idx];

    int pick_curr_to_the_subseq = max_non_adj_subseq_sum_memoization(arr, idx-2, dp) + arr[idx];
    int not_picking_curr_to_the_subseq = max_non_adj_subseq_sum_memoization(arr, idx-1, dp) ;

    return  dp[idx] = max(pick_curr_to_the_subseq, not_picking_curr_to_the_subseq);



}

// tabulation

int max_non_adj_subseq_sum_tabulation(vector<int>arr)
{
    int n = arr.size();
    if(n == 0) return 0;
    if(n == 1) return arr[0];

    vector<int> dp(n, 0);

    dp[0] = arr[0];
    int negative_idx =0;
    for(int i=1; i<n; i++)
    {
       int pick = arr[i];
       if(i>1) pick = dp[i-2] + pick;
       int not_pick = dp[i-1];
       dp[i] = max(pick, not_pick);
    }

    return dp[n-1];

    
}

// optimmized tabulation

int max_non_adj_subseq_sum_optimized_tabulation(vector<int>arr)
{
    int n = arr.size();
    int prev = arr[0];
    int prev_2 =0;    // index  <0

    for(int i =1; i<n; i++)
    {
        int pick = arr[i];
        if(i>1) pick = pick + prev_2;

        int not_pick = prev;
        int  curr = max(pick, not_pick);
        prev_2 = prev;
        prev = curr;

    }
    return prev;

}



int main()
{
    vector<int>arr = {5,1,1};
    int idx  = arr.size()-1;
    vector<int>dp(idx+1, -1);
    cout<<max_non_adj_subseq_sum(arr, idx)<<endl;
    cout<<max_non_adj_subseq_sum_memoization(arr, idx, dp)<<endl;
    cout<<max_non_adj_subseq_sum_tabulation(arr)<<endl;
    cout<<max_non_adj_subseq_sum_optimized_tabulation(arr);
    


    return 0;
}