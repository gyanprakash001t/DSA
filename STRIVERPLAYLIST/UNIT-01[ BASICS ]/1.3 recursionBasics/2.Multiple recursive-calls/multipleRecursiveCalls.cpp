#include <iostream>
using namespace std ;

// find fibonaaci

int fib( int n){
    if (n<=1) return n;
     return fib(n-1) +fib(n-2);
}

//T.C - O(2^n)   not exactly  2^n but exponential

int main(){
cout<<fib(5);
    return 0;
}