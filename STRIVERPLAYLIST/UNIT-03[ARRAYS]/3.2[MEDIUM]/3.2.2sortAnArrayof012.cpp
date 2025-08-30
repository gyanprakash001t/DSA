#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[],int n)
{
 for(int i=0;i<n;i++)
 {
  cout<<arr[i]<<" ";
 }
}

// brute
// TODO:apply mereg sort

//better
void betterSort(int arr[],int n)
{
    int count0=0;
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            count0++;
        }
        else if(arr[i]==1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
       
    }

     for(int i=0; i<count0;i++)
        {
            arr[i]=0;
        }
        for(int i=count0;i<n-count2;i++)
        {
            arr[i]=1;
        }
        for(int i=n-count2; i<n;i++)
        {
            arr[i]=2;
        }
}

// optimal --> dutch national flag algorithm

void optimalSort(int arr[], int n)
{
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;

        }
    }
}

int main()
{
    int arr[]={0,1,2,0,1,2,1,2,0,0,0,1};
    int n =sizeof(arr)/sizeof(arr[0]);
    // betterSort(arr,n);
    optimalSort(arr,n);
    printArray(arr,n);

    return 0;
}