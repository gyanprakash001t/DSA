#include<bits/stdc++.h>
using namespace std;

//iterative
int search(vector<int>& nums, int target) 
    {
        int low = 0; 
        int high =nums.size()-1;
        

        while(low <= high)
        {
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target)
            {
                low = mid+1;  
                
            }
            else
            {
               high = mid-1;
            }
        }
        return -1;


    }

// recursive
int searchRecursive(vector<int>& nums, int target,int low,int high)
{
    
    //base case 
    if(low>high) return -1;
    //kaam
    int mid =(low+high)/2;
    if(nums[mid]==target) return mid;
    else if(nums[mid]<target) low =mid+1;
    else high = mid-1;
    
    searchRecursive( nums,  target, low, high);

   
    
}

    int main()
    {
       

        vector<int> nums = {-1,0,3,5,9,12};
        int target=-1;
        int res=searchRecursive(nums,target,0,5);
        cout<<res;
        return 0;
    }