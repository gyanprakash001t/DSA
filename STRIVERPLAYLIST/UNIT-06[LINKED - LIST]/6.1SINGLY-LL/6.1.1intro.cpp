// what  is struct 

#include<bits/stdc++.h>
using namespace std;

// struct Node {
//     int data;
//     Node* next;

//     Node(int data1, Node* next1){
//         data=data1;
//         next = next1;
//     }
// };


class Node {
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data=data1;
        next = next1;
    }
};

// with struct you don't have properties of OOPs  
// but if you use class to make a custom data type you will have access to the OOPs prop like abstraction, encapsulation, inheritance..

int main(){
vector<int> arr ={2,5,8,7};

// Node y =  Node(arr[0], nullptr);
// cout<<y.data;

Node* y = new Node(arr[0], nullptr);
cout<<y->data;


    return 0;
}