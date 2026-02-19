#include<bits/stdc++.h>
using namespace std;



// findung the k-th largest sum subarray

int kth_largest_sum_subarray(vector<int>&arr, int k)
{
    //declaring a min heap of integers
    priority_queue<int, vector<int>, greater<int>>min_heap;
    for(int i=0;i<arr.size();i++)
    {
        int sum =0;
        for(int j=i; j<arr.size();j++)
        {
           sum += arr[i];
           if(min_heap.size()< k)
           {
            min_heap.push(sum);
           }
           else
           {
                if(min_heap.top() < sum)
                {
                    min_heap.pop();
                    min_heap.push(sum);
                }

           }
             
        }
    }
    return min_heap.top();
}

int main()
{
    return 0;
}