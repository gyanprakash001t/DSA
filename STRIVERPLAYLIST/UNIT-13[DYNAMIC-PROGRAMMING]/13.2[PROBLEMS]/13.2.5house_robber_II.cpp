#include<bits/stdc++.h>
using namespace std ;


// recursion
int max_non_adj_subseq_sum(vector<int>&arr, int idx)
{
    if(idx == 0) return arr[idx];
    if(idx < 0) return 0;

    int pick_curr_to_the_subseq = max_non_adj_subseq_sum(arr, idx-2) + arr[idx];
    int not_picking_curr_to_the_subseq = max_non_adj_subseq_sum(arr, idx-1) ;

    return max(pick_curr_to_the_subseq, not_picking_curr_to_the_subseq );
}

int house_robber_II_recursion(vector<int>&arr)
{
    vector<int>temp1,temp2;
    int n =arr.size();
    for(int i=0; i<n; i++)
    {
        if(i !=0) temp1.push_back(arr[i]);
        if(i != n-1) temp2.push_back(arr[i]);
    }
    int pick = max_non_adj_subseq_sum(temp1, n-1);
    int  non_pick = max_non_adj_subseq_sum(temp2, n-1);
   int max_profit = max(pick, non_pick ) ;
   return max_profit;



}

// si,ilarly for memoization or tabulation



int main()
{
    vector<int>arr ={2, 3, 2};
    cout<<house_robber_II_recursion(arr);
    return 0;
}