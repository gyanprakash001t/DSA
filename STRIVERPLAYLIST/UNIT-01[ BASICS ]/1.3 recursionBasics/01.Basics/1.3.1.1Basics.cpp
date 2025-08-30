#include<iostream>
using namespace std;

//Q1. print the name 5 times

void printName(int i,int n){
  if (i==n)  return;
  cout<<"Gyan"<<endl;
  i++;
  printName(i,n);

};


// Q2.print linearly from 1 to N

void printLineraly(int current,int N){
    if (current>N) return;
    cout<<current<<endl;
    current++;
    printLineraly(current,N);
    
};

//print from N to 1;
void printReverse(int current, int N){
if(current<1)return;
cout<<current<<endl;
current--;
printReverse(current, N);
};

// print from 1 to N  using Backtrack(you can't use i+1)
void PrintLineralyUsingBacktrack(int i, int N){
    if (i<1) return;
    i--;
    PrintLineralyUsingBacktrack(i,N);
    cout<<i+1<<endl;
}
// or
void PrintLineralyUsingBacktrackM2(int i, int N){
    if (i<1) return;
    PrintLineralyUsingBacktrack(i-1,N);
    cout<<i<<endl;
}

//print N to 1 using Backtrack (means you can't use i-- or i-1)
void printReverseUsingBacktrack(int i, int N){
    if(i>N) return;
    printReverseUsingBacktrack(i+1,N);
    cout<<i<<endl;
}

// find sum of N numbers using recursion
int sum=0;
int sumOfNnumbers(int N){
    if(N==0) {
        return 0;
    };
    sumOfNnumbers(N-1);
    sum=sum+N;
   return sum;
}

// or
int sumOfNnumbersM2(int n){
    if (n==0){
        return 0;
    }
    return n+sumOfNnumbersM2(n-1);
}

// find out the factorial of n

int factorial(int n){
    if(n==0)return 1;
    return n*factorial(n-1);
}


int main(){
    // printName(0,5);
    // printLineraly(0,7);
    // printReverse(6,6);
    // PrintLineralyUsingBacktrack(3,3);
    // PrintLineralyUsingBacktrackM2(3,3);
    //printReverseUsingBacktrack(1,3);
   // int sum = sumOfNnumbers(5);
    //   cout<<sum<<endl;
    //   cout<<sumOfNnumbersM2(3)<<endl;
    //cout<<sumOfNnumbersM2(5)<<endl;
    cout<<factorial(4)<<endl;

    return 0;
}