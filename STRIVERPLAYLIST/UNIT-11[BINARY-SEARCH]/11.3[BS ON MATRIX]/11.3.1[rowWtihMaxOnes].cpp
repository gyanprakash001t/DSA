#include<bits/stdc++.h>
using namespace std;

int rowWithMaxOnes(vector<vector<int>>&matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int max_one =-1;
    int row =-1;
    int max_cnt =-1;
     
    for(int i=0; i<n; i++)
    {
        int low = 0;
        int high =m-1;
        while(low<=high)
        {
            // first occurence 
            int mid = (low+high)/2;

            //  comparing the mid 
            if((matrix[i][mid] ==1) && (mid == 0 || matrix[i][mid - 1] == 0) ) 
            {
                max_one =(m-mid);
                if (max_one > max_cnt)
                {
                    max_cnt = max_one;
                    row =i;
                    break;
                }
            }
            else if (matrix[i][mid]>=1)
            {
                high = mid-1;
            }
            else 
            {
                low = mid+1;
            }
            
        }
    }
    return row;
}

// int rowWithMaxOnes(vector<vector<int>>&matrix)
// {


// }