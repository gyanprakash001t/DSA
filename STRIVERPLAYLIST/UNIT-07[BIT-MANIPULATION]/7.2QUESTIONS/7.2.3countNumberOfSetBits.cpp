#include<bits/stdc++.h>
using namespace  std;

// m-1 

int countNumberOfBits( int n)
{
    int cnt= 0;
    while(n!=0)
    {
        if(n&1) cnt++;  // earlier we used to use n%2==1; 
        n=n>>1; // earlier we used to use n=n/2
        // these are equivalent expressions but  faster than arithmetic cause bit operations are faster 
    }
    return cnt;
}

// m-2
 int countNumberOfBitsM2(int n)
 {
    int cnt=0;
    while(n!=0)
    {
        n=n&n-1; // each time this will turn off the rightmost bit(set bit)
        cnt++;
    }
    return cnt;
    //TC : O(no of set bits) 

 }

int main()
{
    int res= countNumberOfBitsM2(16);
    cout<<res;
    return 0;
}