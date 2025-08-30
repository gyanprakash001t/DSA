#include<bits/stdc++.h>
using namespace std;

// check if the i-th bit is set or not

// brute-> convert the given number in to binary and traverse to the  i-th bit from end
// convert binary
 string convert2Binary( int n)
 {
    string res ="";
    while( n !=0)
    {
        if(n%2 ==1) res += "1";
        else res += "0";
        n=n/2;
        
    }
    reverse(res.begin(),res.end());
    return res;
 }


bool chickithBit(int n, int i)
{
     string binary= convert2Binary(n);
     if(binary[binary.length()-1-i] == '1')
     {
        return true;
     }
     else
     {
        return false;
     }

     
}

// optimised  method  ( using bit manipulation)
bool checkithBitM2(int n , int i)
{
     int temp = 1<<i;
     return(temp & n);

}
// using right shift operator
bool checkithBitM2UsingRightShift(int n , int i)
{
     int temp = n>>i;
     return(temp & 1);

}


int main()
{
    string res = convert2Binary(13);
    bool  res2 = chickithBit(13,3);
    bool res3 = checkithBitM2(13,0);
    bool res4 = checkithBitM2UsingRightShift(13,0);
    cout<<res4;
    return 0;
}