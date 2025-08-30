//this is tree series L2  and here we'll code tree ( the basic reperesntation of tree )
/*
🧱 What is a Constructor?
A constructor is a special function inside a class or struct that automatically runs when an object is created.
🔧 Why is it Used?
To initialize values (like setting data, left, right in a tree node).
Ensures that the object starts in a valid state.
Helps avoid writing repetitive code.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
    data=val;
    left = right= nullptr;
    }
};

// preorder traversal using recursion
 void preorder(Node* root, vector<int>&arr){
    if(root == nullptr){
     return;
    };
    arr.push_back(root->data);
    preorder(root->left, arr);
    preorder(root->right, arr);

 };

 vector<int> preOrder(Node* root){
    vector<int> arr; // Create an empty vector to store preorder traversal values
    preorder(root, arr);// Call the preorder traversal function
    return arr;// Return the resulting vector containing preorder traversal values
}

// TODO : DO THE SAME FOR INORDER AND POSTORDER TRAVERSAL AS WELL

//printing the  traversal values directly for different taversal techniques
// preorder traversal
void preorderPrint(Node* root){
    if(root == nullptr){
     return;
    };
    cout<<root->data<< " ";
    preorderPrint(root->left);
    preorderPrint(root->right);

 };

 // inorder traversal 
 void inorderPrint(Node* root){
    if (root== nullptr) return;
    inorderPrint(root->left);
   cout<<root->data<< " ";
    inorderPrint(root->right);
 };

 //postorder traversal 
 void postorderPrint(Node* root){
   if (root== nullptr) return;
   postorderPrint(root->left);
   postorderPrint(root->right);
  cout<<root->data<< " ";
 };

 // TODO : implement the all these functions using stack as well




int main(){

    Node* root = new Node(1);
    /*
    1. new Node(1)
    Creates a new object of type Node on the heap (dynamic memory).
    Calls the constructor of Node with argument 1.
    2. Node* root
    Declares a pointer variable named root that can point to a Node.
    */
    // The -> (arrow operator) is used to access members (like variables or functions) of an object through a pointer.
    root->left =new Node(2);
    root->right = new Node(3);
    root->left->right= new Node (5);
    root->left->left = new Node(4);
    root->left->right->left =new Node(6);
    root->right->left =new Node(7);
    root->right->right =new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
     
    // calling the different traversal functions 
    vector<int> result =preOrder(root);
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    preorderPrint(root);
    cout<<endl;
    inorderPrint(root);
    cout<<endl;
    postorderPrint(root);



    return 0;
}