#include<bits/stdc++.h>
using namespace std;

// brute

bool bs(vector<int>&nums, int target)
{
    int m = nums.size();
    int low=0;
    int high = m-1;
    while(low<= high)
    {
        int mid =(low+high)/2;
        if(nums[mid]== target) return true;
        else if (nums[mid]>target)
        {
            high = mid-1;
        }
        else
        {
            low= mid+1;
        }

    }

    return false;

}
bool searchMatrix1(vector<vector<int>>&matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i =0; i<n; i++)
    {
        if((matrix[i][0]<=target) && (matrix[i][m-1]>=target))
        {
           return bs(matrix[i], target);
        }
    }
    return false;
}

// optimal --> we'll flatten the matrix in linear  and do the calculations accordingly: TC:O(log(mn))
bool searchMatrix(vector<vector<int>>&matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    int high =( m*n)-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        int row = mid/m;
        int col= mid%m;

        if(matrix[row][col] == target) return true;
        // elimination
        if(matrix[row][col]>target)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return false ;

}