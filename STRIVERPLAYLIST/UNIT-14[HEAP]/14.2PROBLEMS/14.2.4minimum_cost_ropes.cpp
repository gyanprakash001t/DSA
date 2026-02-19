#include<bits/stdc++.h>
using namespace std;

/*

// kth smaalest element 

int kth_smallest(vector<int>&arr, int k)
{
   

    // put first k elements in to heap  and then iterate through the next elements in the arr and if you get any element smaller than the top/root  replace and heapify
    // at end top is your answer

     // build max heap of k elements
    priority_queue<int>pq;

    // push first k elements in to the heap
    // now start iterating through array if you  find an element smaller than  top then insert it in to the heap
    // cause heap is of k members  and in max heap  larget will be at top  among  from array pov  pq is set of smallest k numbers 
    // from heap pov on top is largest and kth smallest in arr

    for(int i =0; i<k; i++)
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


*/

// above is wrong method  and it's time complexity is  too bad as well

// IDEA: you have to pick smallest element and then again smallest element  sum up push in to the ans array and then again in to min_heap 

int  minimun_cost(vector<int>&arr)
{
priority_queue<int, vector<int>,greater<int>>min_heap(arr.begin(), arr.end());
int cost =0;

while(min_heap.size()>1)
{
    int first= min_heap.top();
    min_heap.pop();
    int second = min_heap.top();
    min_heap.pop();
    cost += (first +second);
    min_heap.push(first + second);

}
return cost;


}



int main()
{
    vector<int>arr = {4,3,2,6};
    cout<<minimun_cost(arr)<<"";
    return 0;
}