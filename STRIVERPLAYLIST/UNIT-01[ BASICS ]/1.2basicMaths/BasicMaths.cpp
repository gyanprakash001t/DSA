// it's basic maths (vide0 -07)

#include <bits/stdc++.h>
using namespace std;

/*
// extraction of digits  from a given number
int extractionDigits(int n){
    while (n>0) {
       int r =  n%10;
       cout<<r<<endl;
       n=n/10;
    }
*/

/*
//  finding out the number of digits
 int numberOfDigits(int n){
  int count =0;
    while(n>0){
         n=n/10;
         count++;

    }
    cout<<count;

// Alternate method
// int count = int(log10(n) + 1);
// cout<<count;
 
 }

*/

/*
// reversing a number

int reverseNumberM1(int n){
int R=0;
 while (n>0){
 int d= n%10;
 R=R*10 +d;
  n=n/10;
}
cout<<R; 
}


//Alternate and you should never prefer this

int reverseNumberM2(int n){
int count = int(log10(n) + 1);
  int N = 0;
  while (count > 0)
  {
    int d = n % 10;
    N = N + d * static_cast<int>(round(pow(10, count - 1))); // power returns double which was causing issues....You must ensure pow(...) gives correct results:
    count = count - 1;
    n = n / 10;
  }
  cout << N;
}

*/

/*
// checking palindrome 

 void isPalindrome(int n){
  int original = n;
  int R=0;
  //reversing the number
 while (n>0){
 int d= n%10;
 R=R*10 +d;
  n=n/10;
}
if(original==R){
  cout<<"true";
}
else{
cout<< "false";
}
 }
*/


/*
// Armstrong number 
bool isArmstrong(int n){
  int original =n;
  int AN=0;
  int count =int(log10(n)+1);
  while(n>0){

     int d =n%10;
     int result=1;
     int tempCount =count;
          while (tempCount>0){
              result = result*d;
              tempCount--;
         }
       AN += result;
       n=n/10;

  }
  if(original==AN){
    return true;
  }
 return false;
}
*/

/*
// printing all the divisors
 void printAllDivisorsM1(int n){
  int i=1;
  while(i<=n/2){
    if(n%i==0){
      cout<< i<< " ";
    }
    i++;
  }
  cout<<n;
  cout<<endl;
 }

void printAllDivisorsM2(int n){
  vector<int> ls;
  for(int i=1; i<= sqrt(n);i++){
    if(n%i==0){
       ls.push_back(i);
       if(n/i != i ){
        ls.push_back(n/i);
     }
  }
}
sort(ls.begin(),ls.end());
for(auto it :ls){
  cout<<it<< " ";
}
  }
*/
/*
// checking prime 
bool checkPrime(int n){
  int count = 0;
  for (int i = 1; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      count += 1;
      if ((n / i) != i)
      {
        count = count + 1;
      }
    }
  }
  if (count==2){
    return true;
  }
  else{
    return false;
  }
}
*/

// calcualtion of GCD or HCF
int findGCD(int a, int b) {
   for (int i =min(a,b); i>=1; i--)
   {
    if (a%i==0 &&  b%i==0){
     
      return i ;
      break;
    }

   }
}

// calculation of gcd using euclidean algorithm
int gcd(int a, int b){
  while(a>0 && b>0)
  {
    if(a>b) a=a%b;
    b=b%a;
  }

  if(a==0) return b;
  return a;

}

// if you coame here to revise  try to  know the proof of euclidean algorithm 






int main()
{
// extractionDigits(652381);
//numberOfDigits(319765);
//reverseNumberM1(651238);
// reverseNumberM2(1865);
//  isPalindrome(1221);
// bool isAN =isArmstrong(2389);
// cout<<isAN;
// printAllDivisorsM1(0);
// printAllDivisorsM1(13);
// printAllDivisorsM1(213);
// printAllDivisorsM2(34);
// bool isPrime =checkPrime(17);
// cout<<isPrime;
// cout<<findGCD(6,4)<<endl;
// cout<<findGCD(32,64);
cout<<gcd(52,10)<<endl;
cout<<gcd(32,64)<<endl;



  return 0;
}