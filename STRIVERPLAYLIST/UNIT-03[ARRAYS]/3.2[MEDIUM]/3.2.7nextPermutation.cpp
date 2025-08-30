#include<bits/stdc++.h>
using namespace std;


// brute
// you can generate all the permutionas and search them linearly

// better
//STL provides you next_permuatation(A.begin(),A.end()) --> it  changes ypur array to the next possible permutation

// optimal
vector<int>nextPermutation(vector<int>&A)
{
    int index=-1;
    int n= A.size();
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]<A[i+1])
        {
          index = i;
          break;  
        }
    }

    if(index == -1)
    {
        reverse(A.begin(),A.end());
        return A;
    }

    for(int i=n-1;i>=index;i--)
    {
        if(A[i]>A[index])
        {
            swap(A[i],A[index]);
            break;
        }
    }
    reverse(A.begin()+index+1,A.end());
    return A;
}

int main()
{
    vector<int>A={2,1,5,4,3,0,0};
    vector<int>nextarray = nextPermutation(A);
    for(auto it :nextarray)
    {
        cout<<it<<" ";
        it++;
    }
    return 0;
}