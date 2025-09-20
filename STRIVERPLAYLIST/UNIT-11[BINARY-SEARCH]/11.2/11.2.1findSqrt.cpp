#include<bits/stdc++.h>
using namespace std;

// brute (linear search )
int findSqrt(int n)
{
    int ans=1;
    for(int i=0; i<n; i++)
    {
        if(i*i <=n)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }
    return ans;
}

// optimal (logn)
 int sqrt2(int n)
 {
    int low =1;
    int high =  n;
    int ans =1;
    while(low<=high)
    {
        int mid =(low+high)/2;
        if((mid*mid) <= n)
        {
            ans =mid;
            low =mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return ans;
 }






 int main()
 {
    int res =sqrt2(28);
    cout<<res;
    return 0;
 }