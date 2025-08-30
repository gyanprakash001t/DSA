#include<bits/stdc++.h>
using namespace std;

//leader --> iff all the elements in the right should be smaller than current

// brute

vector<int> leaderBrute(int arr[], int n)
{
    vector<int>leaderArray;
    for(int i=0; i<n;i++)
    {
         bool leader=true;
        for(int j= i+1; j<n;j++)
        {
            if(arr[i]< arr[j])
            {
                leader =false;
                break;
            }
        }
        if(leader==true)leaderArray.push_back(arr[i]);
        
    }
    return leaderArray;
}


// optimal
vector<int>leaderOptimal(int arr[], int n)
{
    vector<int>leaderArray;
    int max = INT_MIN;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]>max)
        {
            max=arr[i];
             leaderArray.push_back(max);
        }
       
    }
    return leaderArray;
}

int main()
{ 
    int arr[]={10,22,12,3,0,6};
    int n =sizeof(arr)/sizeof(arr[0]);
    vector<int> leaderArray= leaderOptimal(arr,n);
    for(auto it: leaderArray)
    {
        cout<<it<<" ";
    }
    return 0; 
}