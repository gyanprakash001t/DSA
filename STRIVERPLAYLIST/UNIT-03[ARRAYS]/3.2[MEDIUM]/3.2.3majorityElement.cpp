#include<bits/stdc++.h>
using namespace std;


// brute
int majorityElementByBrute(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=i;j<n;j++)
        {

            if(arr[i]==arr[j])
            {
                count++;
            }
        }

        if(count>n/2)
        {
            return arr[i];
        }
    }
    return -3777775;
}

// better -->using hashmaps

int majorityElementByBetter(int arr[],int n)
{
    map<int,int>mpp;

    for(int i=0;i<n;i++)
    {
        mpp[arr[i]]++;
    }

    for(auto it:mpp)
    {
        if(it.second>n/2)
        {
            return it.first;
        }
    }
    return -52368723;
 
}

//optimal-->moore's voting algorithm  and idea of the algorithm is if an element is a majority then it can't be cancelled 

int majorityElementByOptimal(int arr[],int n)
{
    int cnt=0;
    int el;
    for(int i=0;i<n;i++)
    {
       if(cnt==0)
       {
        el=arr[i];
        cnt++;
       }
       else if(arr[i]==el)
       {
        cnt++;
       }
       else
       {
        cnt--;
       }
    }
    //if it's given that there exist a majority element tthen you won't be needed next block of code to verify 
    int  cnt1 =0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==el)
        {
            cnt1++;
        }
    }
    if(cnt1>n/2)
    {
        return el;
    }
    return-324586;

}

int main()
{
    int arr[]={7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    // int majorityElement= majorityElementByBrute(arr, n);
    // int majorityElement=majorityElementByBetter(arr, n);
    int majorityElement=majorityElementByOptimal(arr, n);
    cout<<majorityElement;
  

    return 0;
}


