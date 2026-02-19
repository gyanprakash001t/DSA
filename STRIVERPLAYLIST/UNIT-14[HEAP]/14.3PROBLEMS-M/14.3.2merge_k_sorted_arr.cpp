#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    int i ;
    int j;
    node(int data, int  row, int col)
    {
        this->data =  data;
        i=row;
        j=col;
    }
};

class compare 
{
    public:
    bool operator() (node* a, node* b)
    {
        return a->data >b->data;

    }
};

vector<int>merge_k_sorted_arrays(vector<vector<int>>&matrix, int k)
{
    vector<int>ans;
    priority_queue<node*, vector<node*>, compare>min_heap;
    // STEP-01: insert the first element of all arrays in to the heap

    for(int i=0; i<k; i++)
    {
        node* temp = new node(matrix[i][0], i, 0);
        min_heap.push(temp);

    }
    
    //STEP-02:popping the  top of min_heap and push_back in to the ans array
    // and pushing the next element of the same array in to the min_heap
    
    while(min_heap.size()>0)
    {
        node* temp = min_heap.top();
        ans.push_back(temp->data);
        min_heap.pop();
        int row = temp->i;
        int col = temp->j;
        if((col+1) <matrix[row].size())
        {
            node* next = new node(matrix[row][col+1], row, col+1);
            min_heap.push( next);

        }
    }

    return ans;



}



int main()
{
    // you will be given a matrix of sorted vectors
    vector<vector<int>>matrix = {
                                 {1, 4, 7, 10},
                                 {2, 5, 8, 11},
                                 {3, 6, 9, 12}
                                };

   for(auto it:merge_k_sorted_arrays(matrix, 3))
   {
       cout<<it<<" ";
   }

    return 0;
}