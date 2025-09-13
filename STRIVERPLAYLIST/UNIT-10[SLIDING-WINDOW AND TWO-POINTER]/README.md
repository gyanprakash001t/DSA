in this section we'll learn about  few  fix pattern questions
 1. CONSTANT WINDOW
  find the  max sum (continous elememt) of given window size
  approach: you can  take a window of size (given ) and two pointers left and right pointing to starting and end of window..
  and eachtime you can l++,r++ until(r<arr.length()-1)
   pseudo code: 
   int sum = loop (l to r);
   int maxSum =sum;
   while(r<n-1)
   {
    sum= sum-arr[l];
    l++;
    r++;
    sum= sum+arr[r];
    maxSum =max(sum, maxSum);
   }

   2.MAX SUBARRAY/SUBSTRING (CONDITION)
   
   I. WITH SUM(<=K)

    brute:  find all the  subArray

    int sum=0;
    int length=0;
    int maxLenth =0
    for (int i=0;i<n;i++)
    {

         sum=0;
         length =0;
        for(int j=i;j<n;j++)
        {
            sum=sum+arr[j];
            
            if(sum <=k)
            { 
                length++; // length = j-i+1; (if you encounters negative numbers as well in the array)
                maxLength = max(length, maxLength);

            }
            else break; 
            // little optimization you can do in brute approach  without it  .. it would keep on checking sum  even iff  it already has achieved sum
            // if there were negative numbers  as well in the  array then  you can't break .. you have check till the end;
        }
        
       
    }

    better approach: using sliding window and two pinter 
    //  we'll have two pointer each pointing to the  first  index intially.. then we'll move right pointer and keep adding the current value to the sum 
    // the moment it  will get greater than desired sum we'll shift the left pointer to the right 

    int l=0,r=0,sum=0,maxLen =0;

    while(r<n)
    {
        sum=sum+arr[r];
        while(sum>k)
        {
            sum= sum-arr[l];
            l++;
        }
        
        
            maxLength = max (maxLength, r-l+1);
        
        r++;

    }


    optimal approach: O(N)

    while(r<n)
    {
        sum=sum+arr[r];
        if(sum>k)
        {
            sum= sum-arr[l];
            l++;
        }
        if(sum<k)
        {
            maxLength = max (maxLength, r-l+1);
        }
        r++;

    }



