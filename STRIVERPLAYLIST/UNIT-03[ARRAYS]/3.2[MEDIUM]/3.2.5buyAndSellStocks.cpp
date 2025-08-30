#include<bits/stdc++.h>
using  namespace std;

// buy and sell stocks such that profit is maximum
int buyAndsellStocks(int arr[], int n)
{
    int minm =arr[0];
    int profit =0;
    for(int i=1;i<n;i++)
    {
       int netSave = arr[i]-minm;
    //    profit = max(profit,netSave);

       if(profit<netSave)
       {
        profit = netSave;
       }

    //    minm =min(minm,arr[i]);

       if(minm>arr[i])
       {
        minm = arr[i];
       }
    }  
    
    return profit;
}

int main()
{
    int arr[]={7,1,5,3,7,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxmProfit= buyAndsellStocks(arr,n);
    cout<<maxmProfit;
}