#include<bits/stdc++.h>
using namespace std;

vector<int> arrangeBySignBrute(vector<int>arr, int n)
{
    vector<int>positive;
    vector<int>negative;
    int j=0;
    int k=0;
    for (int i=0;i<n;i++)
    {
       if(arr[i]>=0) 
       {
        positive.push_back(arr[i]);
       }

       if(arr[i]<0)
       {
       negative.push_back(arr[i]);
       }
    }
    
    for(int i=0;i<n/2;i++)
    {
        arr[2*i]=positive[i];
    }

    for(int i=0;i<n/2;i++)
    {
        arr[(2*i)+1]=negative[i];
    }

    return arr;
}

vector<int>arrangeBySignOptimal(vector<int>arr)
{
    int n =arr.size();
    int posIndex=0;
    int negIndex=1;
    vector<int> ans(n);

    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            ans[negIndex]=arr[i];
            negIndex +=2;
        }
        else
        {
            ans[posIndex] = arr[i];
            posIndex +=2;
        }

    }

   return ans;

}

int main()
{
    vector<int>arr ={3,1,-2,-5,2,-4};
    int n = arr.size();

    // vector<int>ans = arrangeBySignBrute(arr,n);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<ans[i]<<" ";
    // }

    vector<int>ansOptimal =arrangeBySignOptimal(arr);
    for(int i=0;i<ansOptimal.size();i++)
    {
        cout<<ansOptimal[i]<<" ";
    }

    

    return 0;
}