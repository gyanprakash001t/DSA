#include<iostream>
using namespace std;

int main (){
     string s;
     cin>>s;

     //pre compute
     int hash[26]={0};               // string only has lower case character then we can ddeclare the array of size 26
     for(int i=0;i<s.size();i++){
        hash[s[i]-'a'] +=1;
     }

     int q ;
     cin>>q;
     while(q--){
        char input;
        cin>>input;
        // fetch
       cout<<hash[input-'a']<<endl;
     }

    return 0;
}
