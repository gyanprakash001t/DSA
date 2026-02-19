#include<bits/stdc++.h>
using namespace std ;

// print a name  n times recursively 

void print_name(int n, string name )
{
    if (n<=0) return;
    cout<<name;
    cout<<"   ";
    print_name(n-1, name);
}

 void print_reverse(int n)
 {
    if (n< 1) return ;

    cout<<n;
    print_reverse(n-1);
 }

 void print_linearly(int n, int i)
 {
    if (i>n) return;
    cout<<i;
    print_linearly(n,i+1);



 }
 int sum_consecutive(int n, int sum)
 {
    if(n==1)  return sum +1;
    sum = sum +n;
    return sum_consecutive(n-1, sum);

 }


 int factorial(int n)
 {
    if(n<=1) return 1;
    return n*factorial(n-1);

 }

void reverse_arr(vector<int>&arr,int si, int ei)
 {
    if(si>=ei) return ;
    swap(arr[si], arr[ei]);
    return reverse_arr(arr,si+1,ei-1);
 }

 bool check_palindrome(string str, int  si, int ei )
 {
    if (si >= ei  ) return true;
    if(str[si] != str[ei]) return false ;
    return check_palindrome(str, si+1, ei-1);

 }

 int fib(int n)
 {
    if(n==0 || n==1) return n;
    return fib(n-1) +fib(n-2);
 }

 // MERGE SORT [we divide the array till the individual  element and then merge the   smallest subarrays (i.e one element)  such that  final array  comes out to be sorted ]
 void merge(vector<int>&nums, int low, int high)
 {
   vector<int>temp;
   int mid = low +(high-low)/2;
   int i = low;
   int j= mid+1;

    while(i <= mid && j<=high)
    {
      if (nums[i] <= nums[j])
      {
         temp.push_back(nums[i]);
         i++;
      }
      else 
      {
         temp.push_back(nums[j]);
         j++;
      }
    }

    // if one of the subarray ends early


      while(i <= mid)
      {
         temp.push_back(nums[i]);
         i++;
      }
   
      while(j <= high)
       {
         temp.push_back(nums[j]);
         j++;
       }

   // copy your temp to the  nums

   for(int k=0; k< temp.size(); k++)
   {
      nums[low+k]=temp[k];
   }


// you might not understand what is this  how to  copy
// so here is explanation

/* 
First, understand what temp actually is
During merge(nums, low, high):
nums[low … mid] → already sorted
nums[mid+1 … high] → already sorted
temp → new array containing the merged, sorted result
Important:
temp starts at index 0,
but it represents the sorted version of nums[low … high].
*/
   
}


 void merge_sort(vector<int>&nums, int low, int high)
 {
   //base case
   if(low >= high) return;
   int mid = low + (high-low)/2;

   merge_sort(nums, low, mid);
   merge_sort(nums, mid+1, high);
   merge(nums, low, high);


 }



// QUICK S0RT (we choose a pivot  and every time we place  the pivot  at it's correct position and then we   partion our arr in to pi-1 and pi+1  and choose the last elememt of parioned ar
// ray to to place the pivot and right place until  no  further patition possible )

int partition(int low, int high , vector<int>&nums_quick)
{
   int pivot = nums_quick[high];
   int i = low-1;
   int j = low;
   while(j < high)
   {

        if (nums_quick[j] <= pivot)
         {
            ++i;
            swap(nums_quick[i], nums_quick[j]);
            j++;
         }
         else
         {
            j++;
         }
   }
   
   swap(nums_quick[i+1], nums_quick[high]);
   return low+1;

}

void quick_sort(int low, int high, vector<int>&nums_quick)
{
   // base case 
   if (low >= high) return;
   int pi = partition(low,high,nums_quick);
   quick_sort(low, pi-1,nums_quick);
   quick_sort(pi+1, high, nums_quick);
}









int main()
{
    vector<int>nums_quick = {2,5,7,6};
    vector<int>nums = {1,5,7,3,9};
    vector<int>arr ={1,2,3,4,5};
    string str = "gyan";
    int n= 6;
    print_name(n,str);
    cout<<"\n";

    print_linearly(6, 1);
    cout<<"\n";

    print_reverse(n);
    cout<<"\n";

    int sum =sum_consecutive(20,0);
    cout<<sum;
    cout<<"\n";

    int fact = factorial(4);
    cout<<fact;
    cout<<"\n";
 
    reverse_arr(arr,0,arr.size()-1);
    for(int i  =0; i<arr.size();i++)
    {
        cout<<arr[i];
    }
    cout<<"\n";

    for(auto it :arr)
    {
        cout<<it;
    }
    cout<<"\n";

    string str1 = "appa";
    cout<< check_palindrome(str1, 0, str1.length()-1);
    cout<<"\n";

    cout<<fib(6);
    cout<<"\n";

   merge_sort(nums, 0, nums.size()-1);
    for(auto it : nums)
    {
        cout<<it<<" ";
    }
    cout<<endl;


   quick_sort(0, nums_quick.size()-1, nums_quick);
   for(auto it: nums_quick)
   {
      cout<<it<<" ";
   }
   cout<<endl;

    return 0;
}