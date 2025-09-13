#include<bits/stdc++.h>
using namespace std;

// brute 


int longestSubStringWithKDiffCharsBetter(string &s, int k)
   {
        // code here
        int l=0,r=0,maxLength=0;
        map<char,int>mpp;
        int n = s.size();
        while(r<n)
        {
                mpp[s[r]]++;
                while(mpp.size()>k)
                {
                   mpp[s[l]]--;
                   if(mpp[s[l]]==0)mpp.erase(s[l]);
                   l++;
                   
                }
                maxLength =max(maxLength,r-l+1);
                r++;
              
        }
          return maxLength;
    }

int longestSubStringWithKDiffCharsOptimal(string &s, int k)
   {
        // code here
        int l=0,r=0,maxLength=0;
        map<char,int>mpp;
        int n = s.size();
        while(r<n)
        {
                mpp[s[r]]++;
                if(mpp.size()>k)
                {
                   mpp[s[l]]--;
                   if(mpp[s[l]]==0)mpp.erase(s[l]);
                   l++;
                   
                }
                if(mpp.size()>k)
               { 
                maxLength =max(maxLength,r-l+1);
               }
                r++;
              
        }
          return maxLength;
    }
int main()
{
    string s= "acabcd";
    int k=2;
    int res =longestSubStringWithKDiffCharsBetter(s,k);
    cout<<res;
    return 0;
}

 