#include<bits/stdc++.h>
using namespace std;

// brute
// iterating through the array and calculate the XOR with each  element

//optimised -->in constant time

int  findXorInTheRangeoptimised(int n)
{

if(n%4==0)return n;
else if(n%4 ==1) return 1;
else if( n%4 ==2) return 2;
else return 0;
}

// little variation of this problem
// in the case we have  to find XOR  for the numbers in the range

int findXorInTheRangeoptimisedVariation(int n, int m)
{
    int first =  findXorInTheRangeoptimised(n-1);
    int second =   findXorInTheRangeoptimised(m);
    return  first^second;

}

int main()
{
    int res =findXorInTheRangeoptimisedVariation(4,8);
    cout<<res;
    return 0;
}