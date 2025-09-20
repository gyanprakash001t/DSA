#include<bits/stdc++.h>
using namespace std;

// brute


//  we can check left and right for each elemnt and for first and last you can check to right and left respectively 
// and if n==1 then you can return  nums[0];

// optimal
//  since  given numsay is sorted we can use binary search (BS)

// in BS you need to figure out  which part  has to be eliminated 
// and in the given scenario you can observe that (odd, even) -->you are on the right half of the element which needs to be eliminated  cause element is on the left
// and similarly when (even , odd)--> are same means you are on the left part  and element is on the right so left part needs to be eliminated 
int singleElement(vector<int>&nums) 
{
    int n= nums.size();
    // edge cases
    if(n==1) return nums[0];
    if(nums[0] != nums[1]) return nums[0];
    if(nums[n-1] != nums[n-2]) return nums[n-1];
    int low=1; int high= n-2;
    while(low<=high)
    {
      // find out mid
      int mid =(low+high)/2; 
      // compare the mid with desired output
      if(((nums[mid]!=nums[mid+1])&& (nums[mid]!=nums[mid-1]))) return nums[mid];  

      //eliminate portion where you can't find  your answer 
      if(((mid%2 ==1) && (nums[mid-1] == nums[mid])) || ((mid%2 ==0) && (nums[mid] == nums[mid+1])))
      {
        low = mid-1; // eliminate left part
        
      }
      else // elimante  right part
      {
        high = mid-1;  
      }
    }
    return -1;
}