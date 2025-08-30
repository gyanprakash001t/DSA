#include<bits/stdc++.h>
using namespace std;

 // Brute
string twoSumBrute(int arr[],int n, int target)
{
  
 
  for(int i=0;i<n-1;i++)
  {
    int sum=0;
   for(int j=i+1;j<n;j++)
    {
        sum=arr[i]+arr[j];
        if(sum==target)
        {
            return "YES";
        }
    }
  }
  return "NO";
}

//Better
string twoSumBetter(int arr[], int n, int target)
{
    map<int,int>mpp;
    for(int i=0;i<n;i++)
    {
        int a =arr[i];
        int req=target-a;
        if (mpp.find(req) != mpp.end())   //So mpp.find(req) != mpp.end() means: "If req is already in the map." 
        {
            return "YES";  // return{mpp[req],i} --> if been asked to return the index
        }
        else
        {
         mpp[a]=i;  // storing the element and corresponding index
        }
    }
       return "NO";
}

// Optimal

string twoSumOptimal(vector<int>arr, int n, int target)
{
  sort(arr.begin(), arr.end());
  int left=0;
  int right=n-1;
  
  while(left<right)
  {
   int sum= arr[left]+arr[right];
    if(sum>target)
    {
        right--;
        
    }
  else if(sum < target)
    {
        left++;
       
    }
    else
    {
        return "YES";

    }

  }
  return "NO";
}



int main()
{
    // int arr[]={2,6,5,8,11};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int target =14;
    // string answer=  twoSumBrute(arr,n, target);
    // string answer=  twoSumBetter(arr,n, target);
    // cout<<answer;


    vector<int> arrOptimal ={2,6,5,8,11};
    int nOptimal=arrOptimal.size();
    int targetOptimal =9;
    string answerOptimal= twoSumOptimal(arrOptimal,nOptimal,targetOptimal);
    cout<<answerOptimal;



    return 0;
}