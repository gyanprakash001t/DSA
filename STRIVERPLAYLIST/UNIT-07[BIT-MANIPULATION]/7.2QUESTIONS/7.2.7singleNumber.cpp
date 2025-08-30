#include<bits/stdc++.h>
using namespace std;


// in this module we'll find out single number in the array where every other element appear twice
// brute -loop
//better - hashing/hashpmap
//optimal

int findOutSingleNumberInTheArray(vector<int>&nums)
{
    int res=0;
    for(int i=0;i<nums.size();i++)
    {
        res =res^i;
    }
    return res;
}

// a slight variation how'd u find single number if all other appear thrice
//brute -loop
//better -hashing
// optimal


// a variation how can you find two distinct single numbers in the array rest all appears twice
// brute-loop
//better-hashmap
//optimal- using XOR


// 