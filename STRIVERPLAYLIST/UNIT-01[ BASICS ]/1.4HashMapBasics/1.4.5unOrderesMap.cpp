#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin>>n;
    int arr[n];
    unordered_map<int,int>mpp;  // as name suggests it is  unordered  like keys are not store in the sorted fashion
    // T.C.  Storing or fetching will take o(1) in best case or average  case  and  linear in worst case 

    for(int i=0;i<n ;i++){
       cin>>arr[i];
       mpp[arr[i]]++;//compute 
    }

    for (auto it :mpp){
        cout<<it.first<<"-->"<<it.second;
    }

    int q;
     cin>>q;
     while(q--){
        int number ;
        cin>>number;
        cout<<mpp[number];
     }


    return 0;
}

// we have to use unordered maps but when it shows time limit exceeded(TLE)  then we will switch to the maps

//why does the worst case happens --> because of internal collisions 