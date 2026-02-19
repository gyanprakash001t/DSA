// Problem Statement: 

/*Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input. */



#include<bits/stdc++.h>
using namespace std;

void combination_sum_I(vector<int>&arr, vector<vector<int>>&ans, vector<int>&ds, int target, int idx)
{
    // base case
    if(idx >= arr.size() || target < 0) return ;
    // if (target < 0) return;
    if(target == 0)
    {
        ans.push_back(ds);
        return;
    }

    // logic 
    ds.push_back(arr[idx]);
    combination_sum_I(arr, ans, ds, target-arr[idx], idx);
    ds.pop_back();
    combination_sum_I(arr, ans, ds, target, idx+1);

}

int main()
{
    vector<int>arr ={2,3,6,7};
    vector<vector<int>>ans;
    vector<int>ds;
    int target = 7;
    combination_sum_I(arr, ans, ds, target, 0);
    for(auto it : ans)
    {
        for(auto elm : it)
        {
            cout<<elm<<" ";
        }
        cout<<endl;
    }

    return 0;
}