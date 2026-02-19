#include<bits/stdc++.h>
using namespace std;

  void heapify(vector<int>&arr, int size,  int si )
    {
        int largest = si;
        int l = 2*si +1;
        int r = 2*si+2;

        if(l<size && arr[l] > arr[largest]) 
        {
            
            largest =l;
        }

        if(r<size && arr[r] > arr[largest]) 
        {
            largest =r;
        }

        if(largest != si)
        {
            swap(arr[si], arr[largest]);
            heapify(arr, size, largest);
        }

    }


    // this will work for both either two arrays or two max heaps
    void build_heap(vector<int>&arr_1, vector<int>&arr_2, vector<int>&merge_arr)
    {
        // merge both arrays 
        
        int i=0;
        while(i<arr_1.size())
        {
            merge_arr.push_back(arr_1[i]);
            i++;
        }
        i=0;
        while(i<arr_2.size())
        {
            merge_arr.push_back(arr_2[i]);
            i++;
        }

        int n= merge_arr.size();

        // build heap
        for(int i=n/2-1;i>=0;i--)
        {
            heapify(merge_arr, n,i);
        }

    }

    int main()
    {
        vector<int>arr_1 ={23,21,22};
        vector<int>arr_2 ={29,25,28};
        vector<int>merge_arr;
        build_heap(arr_1, arr_2, merge_arr);


        for(auto it:merge_arr)
        {
            cout<<it<<" ";
        }



        return 0;
    }