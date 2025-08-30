#include<bits/stdc++.h>
using namespace std;


//brute

int maximumSubarraySumbyBrute(int arr[], int n)
{
   int maxm =INT_MIN ;
   for(int i=0;i<n;i++)
   {
    int sum=0;
    for(int j=i;j<n;j++)
    {
        sum += arr[j];
         if(sum>maxm)
    {
        maxm=sum;
    }
    }
    if(sum>maxm)
    {
        maxm=sum;
    }
   }
   return maxm;
}

//better (self)
//TODO: can this be a method ..calculate the prefix sum to every index and and try finding out maxm difference b/w prefix sum that will give you maxm sum subarray

// optimal --> kadane's algorithm
// if sum<0 then drop it and sum=0 cause negative starings will always gonna cause you loss 

int maximumsubArraySumByOptimal(int arr[],int n)
{
    int sum=0;
    int maxm =INT_MIN;
    int ansStart =-1;
    int ansEnd =-1;
    int start;
    for(int i=0;i<n;i++)
    {
        if (sum==0)   start =i;  // when we'll start it always be from sum==0
        sum +=arr[i];
        if(sum>maxm) 
        {
            maxm =sum;
            ansStart= start;
            ansEnd= i;


        }
        if(sum<0)
        {
            sum=0;
        }
    }
    return maxm;
}



int main()
{
    int arr[]={-2,-3,4,-1,-2,1,5,-3};
    int n =sizeof(arr)/sizeof(arr[0]);
    // int maximumSubarraySum = maximumSubarraySumbyBrute(arr,n);
    int maximumSubarraySum = maximumsubArraySumByOptimal(arr,n);
    cout<<maximumSubarraySum;
    return 0;
}