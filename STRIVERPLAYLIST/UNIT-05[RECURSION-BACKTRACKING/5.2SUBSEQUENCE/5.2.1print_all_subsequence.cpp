#include<bits/stdc++.h>
using namespace std;


// print all subsequnce
void subsequence(vector<int>&arr, vector<int>&temp, int idx)
{
    if(idx>= arr.size())
    {
        // print temp
        for(auto it :temp)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }

    // choose  current element
    temp.push_back(arr[idx]);
    subsequence(arr, temp, idx+1);

    //no choose current element
    temp.pop_back();
    subsequence(arr, temp, idx+1);


}

// print all subsequence with sum k

// brute
// we caluclate each subseq and then iterate through it to caluclate it's sum  and if sum == target then print it  but it
// will give you  TC: O(n*2^n)

// optimal
// TC:O(2^n) cause we  are not calculating subseq_sum seperately  with each element in temp update the curr_sum variable  with the flow

void subs_with_sum_k(vector<int>&arr, vector<int>&temp, int idx, int target, int curr_sum)
{
    // base case
    if(idx>= arr.size())
    {
        // print temp
        if(curr_sum == target)
        {
             for(auto it :temp)
             {
                cout<<it<<" ";
             }
            
        }
        cout<<endl;
        return;
    }
    
    // choose  current element
    temp.push_back(arr[idx]);
    subs_with_sum_k(arr, temp, idx+1, target, (curr_sum + arr[idx]));

    //no choose current element
    temp.pop_back();
    subs_with_sum_k(arr, temp, idx+1, target, curr_sum);
       
       
}


// print only one subsequence with sum k

// brute 
//   if you think  to pass a  bool flag which is intially false and   we print subsequence only if flag is false cause once sum== k we'll update  bool to true  but  it 
//   won't help much  cause you still  make all the recursive calls but you are not printing so we need to find an solution where after first  yime it prints no more recursive calls happen
//  that will make solution mopre efficient

//optimal

bool subsequence_with_sum_k_onlyone(vector<int>&arr, vector<int>&temp, int idx, int k, int curr_sum)
{
    if(idx>=arr.size())
    {
        if (curr_sum == k )
        { 
            for(auto it: temp)
            {
                cout<<it<<" ";
            }
            return true;
        
        }
         else return false ;
    }
   

    temp.push_back(arr[idx]);
    if(subsequence_with_sum_k_onlyone(arr,temp, idx+1,  k, curr_sum +arr[idx]) == true) return true;

    temp.pop_back();
    if(subsequence_with_sum_k_onlyone(arr,temp, idx+1,  k, curr_sum) == true) return true;

    return false;

}


// on the basis of above we need to find out  number of subsequence with sum k

int  subsequence_with_sum_k_total(vector<int>&arr, int idx, int k, int curr_sum)
{
     if(idx>=arr.size())
    {
        if (curr_sum == k )
        { 
            return 1;
        
        }
        else return 0 ;

    }

    int  l = subsequence_with_sum_k_total(arr, idx+1,  k, curr_sum +arr[idx]);
    int  r = subsequence_with_sum_k_total(arr, idx+1,  k, curr_sum );

    return l+r;

}


// finding subsequence with bit manipulation


int main()
{
    vector<int>arr ={2,1,3,4,-1};
    vector<int>temp;

    // subsequence(arr, temp, 0);
    // subsequence_with_sum_k_onlyone(arr, temp, 0,5,0 );
    int total_subseq_withsum_K= subsequence_with_sum_k_total(arr,0,3,0);
    cout<< total_subseq_withsum_K;
    return 0;
}