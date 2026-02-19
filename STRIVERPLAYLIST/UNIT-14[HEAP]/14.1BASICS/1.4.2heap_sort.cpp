    
   #include<bits/stdc++.h>
   using namespace std;

/* It assumes:
Left subtree of i is already a heap
Right subtree of i is already a heap
Only node i might violate heap property
If this assumption is false → heapify won’t fully fix the tree
*/
   
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
    
    //  heap sort
    // it converts  convert  given array in to heap and then  repeateddly  swaps the last element with the root and decrese the size 
    void heap_sort(vector<int>&arr)
    {
        int n = arr.size();

        // Build heap (rearrange vector)
        for(int i= n/2-1; i>=0; i--)
        {
            heapify(arr, n, i);
        }

        // One by one extract an element from heap
        for(int i = n-1; i>=0; i--)
        {
            // Move current root to end
            swap(arr[0], arr[i]);

            // Call max heapify on the reduced heap
            heapify(arr, i, 0);


        }

    }

    int main()
    {
        vector<int>arr =  {23,54,34,12};
        heap_sort(arr);
        for(auto it : arr)
        {
            cout<<it<<" ";
        }
        return 0;
    }