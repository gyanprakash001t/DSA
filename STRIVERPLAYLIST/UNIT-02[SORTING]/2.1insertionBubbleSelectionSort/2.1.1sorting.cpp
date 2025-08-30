#include<bits/stdc++.h>
using namespace  std;

void printArray(int arr[],int si,int n)
{
    for(int i=si;i<n;i++)
    {
      cout<<arr[i]<<" ";
    }
}

// selection sort-->select the smallest and place it to the first
void selectionSort(int arr[], int si, int n)
{ 
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i;j<=n-1;j++)
        {
            if(arr[j] < arr[min])
            {
               min=j;
            }
        }
      swap(arr[i], arr[min]);

    }
}

//Bubble sort--> pushes maximum element  to the last by starting from the first element and comapring it with
//the next element in the  order it will finds the maximum and we also keep on swapping the maximum  to the  rightmost
// In bubble sort, the outer loop controls the number of passes, and the inner loop compares adjacent elements and swaps them if needed.

void bubbleSort(int arr[],int si,int n)
{
    for(int i= si; i<n-1; i++) // for no of passes (i.e = n-1)
    {
    for(int j=0;j<n-1-i;j++)
      {
        if(arr[j]>arr[j+1])
        {
            swap(arr[j],arr[j+1]);
        }
      }
    }
    
}

// insertion sort--> takes an element and places it to it's correct position

void insertionSort(int arr[], int si, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

//TODO : write the recursive functions as well and figure out how these sorting techniques are different from another



int main(){
    int arr[]={13,46,24,52,20,9};
    int n = sizeof(arr) / sizeof(arr[0]);  // Gives number of elements
    // selectionSort(arr, 0, n);
    // bubbleSort(arr,0,n);
    // insertionSort(arr,0,n);

    printArray(arr,0,n);
    return 0;
}