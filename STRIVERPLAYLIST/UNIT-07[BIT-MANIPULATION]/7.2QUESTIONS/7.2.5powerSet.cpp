#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets(vector<int>& nums) {
        int n= nums.size();
        int subsets =  1<<n;
        vector<vector<int>>subsetVector;
        
        for(int i =0 ;i<subsets;i++)
        {
            vector<int>subset;
            for(int j=0;j<n;j++)
            {
                if(i &(1<<j))
                {
                   subset.push_back(nums[j]);
                }

            }
            subsetVector.push_back(subset);
        }
        return subsetVector;
        


    }

    int main()
    {
        vector<int>nums={1,2,3} ;
       vector<vector<int>>result =subsets(nums);
       for(auto it: result)
       {
         for(auto it1:it)
         {
            cout<<it1<<" ";
         }
         cout<<endl;

       }
   
        return 0;
    }