#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    
    }
    
    //pre-compute
    map<int, int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;  // increment the magnitude  by 1  of frequency/value for the key arr[i]
    }
// map stores all the values  in sorted order....
// for(auto it:mpp){   // this way  you can iteratate thr map with the help of auto type iterator
//     cout<<it.first <<" "<<it.second<<endl;
// }

    int q ;
    cin>>q; // number of queries
    while(q--){
        int number ;
        cin>>number;
        //fetch
       cout<<mpp[number]<<endl;  // number-->key it will check the valueof given key
    }

    return 0;
}
