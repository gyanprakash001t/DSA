#include<bits/stdc++.h>
using namespace std;

int kth_smallest_element(vector<int>&arr, int k)
{
    // build max heap of k elements
    priority_queue<int>pq;

    // push first k elements in to the heap
    // now start iterating through array if you  find an element smaller than  top then insert it in to the heap
    // cause heap is of k members  and in max heap  larget will be at top  among  from array pov  pq is set of smallest k numbers 
    // from heap pov on top is largest and kth smallest in arr

    for(int i =0; i<k;i++)
    {
        pq.push(arr[i]);
    }

    for(int i=k; i<arr.size();i++)
    {
        
       
        if(arr[i] < pq.top())
        {
             pq.pop();
             pq.push(arr[i]);

        }        
        
    }
    return pq.top();

}

//alternative approach using  quickselect

int partion_index(vector<int>&arr, int si, int ei)
{
    int pivot= arr[ei];
    int i=si;
    for(int j=si;j<ei; j++)
    {
        if(arr[j] <pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }

    }
    swap(arr[i], arr[ei]);
    return i;
}

int quick_select(vector<int>&arr, int si, int ei,int k)
{
    if(si <= ei)
    {

    int p_idx =partion_index(arr, si, ei);
    if(p_idx == k-1) return arr[p_idx];
    if(p_idx < k-1)
    {
        return quick_select(arr, p_idx+1, ei, k);
    }
    else
    {
        return  quick_select(arr, si, p_idx-1, k);
    }

    }
    return -1;

}


int main ()
{
    vector<int>arr = {1,3,4,5};
    // cout<<kth_smallest_element(arr, 1)<<endl;
    // cout<<kth_smallest_element(arr, 2)<<endl;
    // cout<<kth_smallest_element(arr, 3)<<endl;
    // cout<<kth_smallest_element(arr, 4)<<endl;

     cout<<quick_select(arr,0, arr.size()-1, 1);


    return 0;
}