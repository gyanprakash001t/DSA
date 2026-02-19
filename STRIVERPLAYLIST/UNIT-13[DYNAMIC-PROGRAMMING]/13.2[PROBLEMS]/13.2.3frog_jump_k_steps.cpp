// a frog  can jum k steps ;
//it has to reach first stair 

#include<bits/stdc++.h>
using namespace std;

// recursive  solution
int min_energy_recursion(vector<int>& height, int idx, int k)
{
    if(idx == 0) return 0;
    int min_energy = INT_MAX;

    for(int i=1; i<=k; i++)
    {
        if((idx-i)>=0)
        {
            int path_energy = min_energy_recursion(height, idx-i, k) + abs(height[idx]-height[idx-i]);
            min_energy = min(min_energy, path_energy);

        }
    }
    return min_energy;

}

//memoization (top-down) 
// dp array
// TC :O(nk), SC: O(n) + O(n)-->recursion_stack

int min_energy_memoization(vector<int>&height, int k, vector<int>&dp,int idx)
{
    if(idx == 0) return 0;
    int min_energy = INT_MAX;
    if(dp[idx] != -1) return dp[idx];

    for(int i =1; i<=k; i++)
    {
        if((idx-i) >=0)
        {
            int path_energy = min_energy_memoization(height, k, dp, idx-i) + abs(height[idx]-height[idx-i]);
            min_energy = min(min_energy, path_energy);
           dp[idx] = min_energy;

        }
        
    }
    return dp[idx];

}

// tabulation

int min_energy_tabulation(vector<int>height, int k)
{
    vector<int>dp(height.size(), 0);
    int n= height.size();
    
    dp[0]=0;
    for(int i=1; i<n; i++)
    {
        int min_energy = INT_MAX;
        for(int j=1; j<=k; j++)
        {
            if((i-j)>=0)
            {
                int path_energy = dp[i-j] + abs(height[i]-height[i-j]);
                min_energy = min(path_energy, min_energy);
                dp[i]= min_energy;

            }
            

        }
    }
    return dp[n-1];
}

// optimized tabulation: at best space complexity will be O(k) cause we need to track last k values to find next value 

int min_energy_optimized_tabulation(vector<int>&height, int k)
{
    vector<int>dp(k, 0);
    int n= height.size();
    dp[0]=0;
    
    for(int i =1; i<n; i++)
    {
        int min_energy = INT_MAX;
        for(int j = 1; j <= k; j++)
        {
            if(i - j >= 0)
            {
                int prev_index = (i - j) % k;
                int path_energy = dp[prev_index] + abs(height[i] - height[i - j]);
                min_energy = min(min_energy, path_energy);
            }
        }

        dp[i % k] = min_energy;

    }
    return dp[(n - 1) % k];

}

int main()
{   vector<int>height = {30, 10,60, 10,60};
    vector<int>dp(height.size(), -1);
    int idx = height.size()-1;
    int k =2;

    // function call
    // cout<<min_energy_recursion(height, idx, k)<<endl;
    // cout<<min_energy_memoization(height, k, dp, idx)<<endl;
    // cout<<min_energy_memoization(height, k, dp, idx)<<endl;
    cout<<min_energy_memoization(height, k, dp, idx)<<endl;
    cout<<min_energy_tabulation(height, k)<<endl;

    return 0;
}