#include<bits/stdc++.h>
using namespace std;

class heap
{
    public:
    vector<int>arr;
    int size;

    // constructor to initialize the value of array
    heap()
    {
        arr.push_back(-1);
        size=0;
    }

    // method to insert
    void insert(int val)
    {
        size = size + 1;
        int index = size;

        // insert at the end
        arr.push_back(val);

        // shit it to the correct position
        while(index>1)
        {
            int parent = index/2;
            if(arr[index]>arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent ;

            }
            else 
            {
                return;
            }
        }

    }

    // deletion from a heap (by default it means we are talking about deleting root  node)

    void heapify(vector<int>&arr, int size,  int si )
    {
        int largest = si;
        int l = 2*si;
        int r = 2*si+1;

        if(l<=size && arr[l] > arr[largest]) 
        {
            
            largest =l;
        }

        if(r<=size && arr[r] > arr[largest]) 
        {
            largest =r;
        }

        if(largest != si)
        {
            swap(arr[si], arr[largest]);
            heapify(arr, size, largest);
        }

    }

    void delete_from_heap()
    {
        if(size ==0) 
        {
            cout<<"nothing to delete";
            return;
        }

        // STEP-01:  put the last node to the first
        arr[1]=arr[size];
        arr.pop_back();
        size--;

        //STEP-02:  take root  to it's correct position
        heapify(arr,size, 1 );

        
    }

   

    // method to print
    void print()
    {
        for(int i=1; i<=size; i++ )
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};


int main()
{
    heap h;
    h.insert(60);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.insert(70);

    h.print();
    h.delete_from_heap();
    h.print();



    return 0;
}