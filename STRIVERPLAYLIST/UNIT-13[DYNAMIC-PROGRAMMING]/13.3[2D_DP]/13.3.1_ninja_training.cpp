
//  you are given with a matrix where each element represent a day and it's elements represent the mrit point for the different task on the day
//  ninja have to maximise merit points with a condition that  chosing the same task on  two consecutive days is not allowed 

//  since you need to explore all the combination you will be needed recursion cause you need to find maximum so greedy won't be able to solve it

// recursive solution  (traversing from last to first cause it makes the memoization easier)
#include<bits/stdc++.h>
using namespace std;

int merit_points_recursion(vector<vector<int>> &grid,  int idx, int last_task )
{
    // base case 
    if(idx ==0) 
    {
        int maxm =0;
        for(int i=0; i< grid[0].size(); i++)
        {
            if(i !=last_task)
            {
                maxm = max(maxm, grid[0][i]);
            }
        }
    }

    // logic 
    int maxm_point = 0;
    for(int i =0; i<grid[0].size(); i++)
    {
        if(i != last_task)
        {
           int merit_points = grid[idx][i] + merit_points_recursion(grid, idx-1, i);
           maxm_point = max(merit_points, maxm_point);
        } 

    }

    return maxm_point;  
}

// memoization
int merit_point_mwmoization(vector<vector<int>> &grid,  int idx, int last_task, vector<vector<int>>&dp)
{
    // base case 
    if(idx ==0) 
    {
        int maxm =0;
        for(int i=0; i< grid[0].size(); i++)
        {
            if(i !=last_task)
            {
                maxm = max(maxm, grid[0][i]);
            }
        }
    }
    
    //checks if the call has already been made
    for(int i=0; i< grid[0].size(); i++)
    {
        if(dp[idx][i] != -1) return dp[idx][i];

    }


    // logic 
    int maxm_point = 0;
    for(int i =0; i<grid[0].size(); i++)
    {
        if(i != last_task)
        {
           int merit_points = grid[idx][i] + merit_point_mwmoization(grid, idx-1, i, dp);
           maxm_point = max(merit_points, maxm_point);
           
        } 

    }

    return dp[idx][last_task] = maxm_point;  
}





int main()
{
    vector<vector<int>>grid ={
                              {3,42,1},
                           };

    vector<vector<int>>dp(grid.size(), vector<int>(4,-1));

    // when we call we use n-1, 3( to ensure all the combinations are considered)
    return 0;
}