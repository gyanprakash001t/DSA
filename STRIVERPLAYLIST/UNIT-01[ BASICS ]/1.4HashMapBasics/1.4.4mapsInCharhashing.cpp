#include<bits/stdc++.h>

using namespace std;

int main(){
  string str;
  cin>>str;

    
    //pre-compute
    map<char, int>mpp;
    for(int i=0;i<str.size();i++){
        mpp[str[i]]++;  
    }

    // fetching values of q queries one by  one
    int q ;
    cin>>q; 
    while(q--){
        char character ;
        cin>>character;
        cout<<mpp[character];
    }

    return 0;
}

// T.C 
// storing or fetching -->log(n) in all cases best, worst or average
