#include<bits/stdc++.h>
using namespace std;

// you  will be given with array of 0 and 1 and you have to find maximum length of subArray while  you can flip atmost k 0s 

// brute

int maxConsecutiveOnesBrute(vector<int>&arr, int k)
{
    int n = arr.size();
    int maxLength=0;
    for(int i=0; i<n; i++)
    {
        int zeros =0;
        int length =0;
        for(int j=i; j<n; j++)
        {
             
            if(arr[j]==0)
            {
               
                zeros++;
            }
            if(zeros>k) break;
            length =j-i+1;
            maxLength = max(length, maxLength);
           
        }
        
        
    }
    return maxLength;
}

// better
int maxConsecutiveOnesBetter(vector<int>&arr, int k)
{
    int l=0,r=0,maxLength=0;
    int n = arr.size();
    int zeros=0;
    int length =0;
    while(r<n)
    {
        if(arr[r]==0)zeros++;

        while(zeros>k)
        {
            if(arr[l]==0)
            {
                zeros--;
            }
            l++;
        }  // this will ensure that left pointer is  at correct position
        
        if(zeros<=k)
        {
        length = r-l+1;
        maxLength = max(length, maxLength);
        }
         r++;

    }  
    return maxLength;

}


//optimal
int maxConsecutiveOnesOptimal(vector<int>&arr, int k)
{
    int l=0,r=0,maxLength=0;
    int n = arr.size();
    int zeros=0;
    int length =0;
    while(r<n)
    {
        if(arr[r]==0)zeros++;
 
        if(zeros>k)
        {
            if(arr[l]==0)
            {
                zeros--;
            }
            l++;
        }  // 
        
        if(zeros<=k)  // this will not allow to update the length until  number of zeros <=k
        {
        length = r-l+1;
        maxLength = max(length, maxLength);
        }
         r++;

    }  
    return maxLength;

}


int main()
{
    vector<int>arr ={1,1,1,0,0,0,0,1,1,1,1,1,0};
    int k=2;
    int res = maxConsecutiveOnesOptimal(arr,k);
    cout<<res;
    return 0;
}

