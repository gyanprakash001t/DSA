// Problem Statement: Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination..

#include<bits/stdc++.h>
using namespace std ;

void combination_sum_II(vector<int>&candidates, vector<vector<int>>&ans, vector<int>&temp, int target, int idx)
{
    if(target ==0) 
    {
        ans.push_back(temp);
        return;
    }

        for (int i = idx; i < candidates.size(); i++) 
        {

        // skip duplicates at same level
        if (i > idx && candidates[i] == candidates[i - 1])
            continue;

        // pruning (since array is sorted)
        if (candidates[i] > target)
            break;


        temp.push_back(candidates[i]);
        combination_sum_II( candidates,ans, temp, target - candidates[i], idx+1);

        temp.pop_back(); 
    }
}



int main()
{

    vector<int> candidates = {10,1,2,7,6,1,5};
    sort(candidates.begin(), candidates.end());
    int target = 8;
    vector<vector<int>> ans;
    vector<int> temp;
    combination_sum_II(candidates, ans, temp, target, 0);
    for(auto v : ans)
    {
        for(auto it: v)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;

}