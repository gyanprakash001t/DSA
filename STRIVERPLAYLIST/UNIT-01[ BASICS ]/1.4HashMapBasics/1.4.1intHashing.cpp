#include<iostream>
using namespace std;



int main (){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }

// precompute
int hash[13]={0};
for(int i=0; i<n; i++){
    hash[arr[i]] +=1;
}

int q ;
cin>>q;
while(q--){      // shorthand for(whileq>0){ //code // q--}
   
    int number;
    cin>>number;

//fetch
    if (number >= 0 && number < 13)
    {
        cout << hash[number] << endl;
    }
    else
    {
        cout << "Number out of range" << endl;
    }
}

    return 0;
}

