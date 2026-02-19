// a frog can jump  one step or two step
// and has to reach the first step;

// there are n stairs we'll  take it as 0 to n-1;
// cause the height array indicates the same height[0] = height of first stair 

#include<bits/stdc++.h>
using namespace std;

// recursive 
int min_energy_req(vector<int>&height, int idx)
{
    // n= stairs
    if(idx == 0) return 0;
    
    int left = min_energy_req(height, idx-1) + abs(height[idx]-height[idx-1]);
    int right = INT_MAX;
    if(idx>1)
    {
    right = min_energy_req(height, idx-2) + abs(height[idx]-height[idx-2]);
    }

    return min(left, right);

}

// memoization
// one parameter is changing that is index
// so you  will be needed an  1D array
int min_energy_memoization(vector<int>&height, vector<int>&dp, int idx)
{
    if(idx == 0) return 0;

    if(dp[idx] != -1) return dp[idx];
    int left = min_energy_memoization(height,dp, idx-1) + abs(height[idx]-height[idx-1]);
    int right = INT_MAX;
    if(idx>1)
    {
    right = min_energy_memoization(height, dp, idx-2) + abs(height[idx]-height[idx-2]);
    }

    return dp[idx]= min(left, right);


    
}

// tabulation(bottom-up)
int min_energy_tabulation(vector<int>&height)
{
    vector<int>dp(height.size());
    dp[0]=0;
    for(int i=1; i<height.size(); i++)
    {
        int left = dp[i-1] + abs(height[i]-height[i-1]);
        int right = INT_MAX;
        if(i>1) 
        {
         right = (dp[i-2] +abs(height[i]-height[i-2]));
        }
        dp[i] = min(left, right);
    }

    return dp.back();
}


// space optimization in tabulation
int min_energy_optimized_tabultion(vector<int>&height)
{
    int prev_1 =0;
    int prev_2 =0;
    int curr =0;
    for(int i=1; i<height.size(); i++)
    {
        int left = prev_1 + abs(height[i]-height[i-1]);
        int right = INT_MAX;
        if(i>1) 
        {
         right = prev_2 +abs(height[i]-height[i-2]);
        }
        curr = min(left, right);

        prev_2 =prev_1;
        prev_1 = curr;
    }

    // cuase when loop  ends i will point to n  and prev_1 will be last element 
    return prev_1;


}

int main()
{
    vector<int>height = {30, 10,60, 10,60};
    int  stairs = height.size()-1;
    vector<int>dp(stairs+1, -1);
    cout<<min_energy_req(height, stairs)<<endl;
    cout<<min_energy_memoization(height, dp, stairs)<<endl;
    cout<<"hello"<<endl;
    cout<<min_energy_tabulation(height)<<endl;
    cout<<min_energy_optimized_tabultion(height)<<endl;

    return 0;
}