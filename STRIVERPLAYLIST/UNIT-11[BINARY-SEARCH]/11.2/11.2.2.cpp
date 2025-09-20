#include <bits/stdc++.h>
using namespace std;

//  O(log(n))
int power(int base, int exp)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = result * base;
            exp--;
        }
        base = base * base;
        exp = exp / 2;
    }
    return result;
}

// brute O(n)
// for( 1  to  m)
// if(power(i,n )== m) return i 
// worst case n=1 runs n times

// find  nth root (BS)
int nthRoot(int n, int m)
{
    int low = 1;
    int high = m;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // check the mid
        if (power(mid, n) == m)
            return mid;

        // elimination of portion where you can’t find your answer
        else if (power(mid, n) > m)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}


int main()
{
    int res = nthRoot(3, 729);
    cout<<res;
    return 0;
}