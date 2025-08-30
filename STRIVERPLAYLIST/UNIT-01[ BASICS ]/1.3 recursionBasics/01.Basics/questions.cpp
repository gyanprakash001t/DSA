#include<iostream>
using namespace std;


//reverse the array

void swap(int arr[], int si, int ei){
      int x = arr[si];
      arr[si]=arr[ei];
      arr[ei]=x;  
    }
void reverseArray(int arr[], int si, int ei){
    if (si>=ei) return;
    swap(arr,si,ei);
    reverseArray(arr,si+1,ei-1);

   

};
// Note: you can't write nested function in C++, i.e function inside a function
// there is a swap [ x1, x2] function available in c++ can be used to swap two vales directly



// reverse the array without using second pointer ei

void swap1(int arr[], int si, int n){
      int x = arr[si];
      arr[si]=arr[n-1-si];
      arr[n-1-si]=x;  
    }
    void reverseArray1(int arr[], int si, int n){
        if(si>=n/2) return;
        swap1(arr, si,n);
        reverseArray1(arr,si+1, n);

    }

// find out the string is whether the palindrome or no

bool checkPalindrome(string str, int i , int n){
    if ( i<=n/2 && str[i] != str[n-1-i]) return false;
    if(i>n/2) return true;
  return  checkPalindrome(str,i+1,n);

}


int main (){
    int arr[]={1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]); // find array length

    reverseArray1(arr,0,n);
     for(int i=0; i<=n-1; i++){
        cout<<arr[i];
    }  


    cout<<endl;
    cout<<endl;
    cout<<endl;

    string str= "dffcdffd";
    int m = str.length();
    cout<<checkPalindrome(str,0,m)<<endl;

    return 0;
}