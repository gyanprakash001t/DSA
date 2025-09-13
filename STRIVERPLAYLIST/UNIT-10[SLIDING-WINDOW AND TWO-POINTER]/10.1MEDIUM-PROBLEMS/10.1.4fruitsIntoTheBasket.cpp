#include<bits/stdc++.h>
using namespace std;

int fruitsIntoTheBasketBrute(vector<int>&arr, int k)
{
    int maxLength=0;
    int n =arr.size();
    for(int i=0; i<n; i++)
    {
        set<int>st;
        for(int j=i; j<n; j++)
        {
            st.insert(arr[j]);
            if(st.size()<=k)
            {
                maxLength =max(maxLength,j-i+1);
            }
            else
            {
                break;

            }
        }
    }
    return maxLength;
}

int fruitsIntoBasketBetter(vector<int>&arr,int k)
{
    int maxLength =0,r=0,l=0;
    int n= arr.size();
    map<int,int>mpp;
    while(r<n)
    {
        mpp[arr[r]]++;
        while(mpp.size()>k)
        {
            mpp[arr[l]]--;
            if(mpp[arr[l]]==0)mpp.erase(arr[l]);
            l++;
        }
        maxLength = max(maxLength, r-l+1);
        r++;
        return maxLength;
    }
}

int fruitsIntoBasketOptimal(vector<int>&arr,int k)
{
    int maxLength =0,r=0,l=0;
    int n= arr.size();
    map<int,int>mpp;
    while(r<n)
    {
        mpp[arr[r]]++;
        if(mpp.size()>k)
        {
            mpp[arr[l]]--;
            if(mpp[arr[l]]==0)mpp.erase(arr[l]);
            l++;
        }
        if(mpp.size()<=k)
        {
            maxLength = max(maxLength, r-l+1);
        }
        
        r++;
        
    }
    return maxLength;
}

int main()
{
    vector<int>arr = {3,3,3,1,2,1,1,2,3,4};
    int k=2;
    int res =fruitsIntoBasketOptimal(arr,k);
    cout<<res;
    return 0;
}
