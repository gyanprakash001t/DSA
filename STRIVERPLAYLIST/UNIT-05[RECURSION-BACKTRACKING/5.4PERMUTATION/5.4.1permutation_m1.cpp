// you are given an array and have to generate all the permutations 

#include<bits/stdc++.h>
using namespace std;

void permutations_m1(vector<int>&nums, vector<int>&ds,vector<vector<int>>&ans, vector<int>&freq)
{
    if(ds.size()== nums.size())
    {
        ans.push_back(ds);
        return ;
    }

    for(int i=0; i<nums.size(); i++)
    {
        if(!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i]=1;
            permutations_m1(nums,ds,ans,freq);
            freq[i]=0;
            ds.pop_back();
        }

    }
}

int main()
{
    vector<int>nums = {1,2,3};
    vector<int>ds;
    vector<int>freq(nums.size(), 0);
    vector<vector<int>>ans;

    permutations_m1(nums, ds , ans ,freq);

    for (auto it : ans)
    {
        for(auto elm : it)
        {
            cout<<elm<<" ";
        }
        cout<<endl;
    }


    return 0;
}

// Initialize a vector of 5 integers, all set to 10.
// vector<int> myVector(5, 10);