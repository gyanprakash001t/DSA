//you are given an array and have to generate all the permutations  without freq array

#include<bits/stdc++.h>
using namespace std ;

void permutations_m2(vector<int>&nums, vector<vector<int>>&ans, int idx)
{
    if(idx >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for(int i=idx; i<nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        permutations_m2(nums, ans, idx+1);
        swap(nums[idx], nums[i]);
    }
}

int main()
{
    vector<int>nums = {1,2,4,3};
    vector<vector<int>> ans ;
    permutations_m2(nums, ans, 0);

    for(auto it: ans)
    {
        for(auto elm: it )
        {
            cout<<elm<<" ";
        }
        cout<<endl;
    }
    return 0;
}