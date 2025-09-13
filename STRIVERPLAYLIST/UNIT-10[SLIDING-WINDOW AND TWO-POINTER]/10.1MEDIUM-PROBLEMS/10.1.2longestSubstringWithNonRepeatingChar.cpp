#include<bits/stdc++.h>
using namespace std;


// brute

 string longestNonRepeatingCharSubString(vector<char>& str)
 {

    int length = str.size();
    int maxLength =0;
    string maxSubString ="";
    for(int i=0; i<length; i++)
    {
        int hash[256] ={0};
        string subString ="";
        // int subStringLength=0;
        for(int j=i; j<length;j++)
        {
           
            if(hash [str[j]]==1) break;
            subString += str[j];
            // subStringLength =j-i+1;
            hash[str[j]] = 1; 
            // maxLength = max(subStringLength,maxLength);
        }
         maxSubString = (maxSubString.length() > subString.length())? maxSubString:subString;
    }
    return maxSubString;
 }

int main()
{
     vector<char> str = {'a', 'b', 'c', 'd', 'e', 'e', 'b', 'b'};
    string longestSubString = longestNonRepeatingCharSubString(str);
    cout<<longestSubString<<endl;
    
    return 0;
}