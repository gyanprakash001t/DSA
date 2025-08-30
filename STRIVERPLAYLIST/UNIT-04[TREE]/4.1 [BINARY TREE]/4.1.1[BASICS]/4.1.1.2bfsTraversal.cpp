// preorder -- root -->left-->right

#include<bits/stdc++.h>
using namespace std;

struct Node 
{
       int data;
       struct Node* left;
       struct Node* right;
       Node( int val)
       {
        data=val;
        left=nullptr;
        right=nullptr;
       }

 };


void preOrder(  Node* root)
{

    if(root==nullptr)
    {
      return;  
    }
    cout<< root->data <<" ";
    preOrder(root->left);
    preOrder(root->right);


};

void postOrder(  Node* root)
{

    if(root==nullptr)
    {
      return;  
    }
    
    postOrder(root->left);
    postOrder(root->right);
    cout<< root->data <<" ";


};
void inOrder(  Node* root)
{

    if(root==nullptr)
    {
      return;  
    }
    
    inOrder(root->left);
    cout<< root->data <<" ";
    inOrder(root->right);
    


};


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    cout<<"Pre-Order traversal :";
    preOrder(root);
    cout<< endl;

    cout<<"In-Order traversal :";
    inOrder(root);
    cout<< endl;

    cout<<"Post-Order traversal:";
    postOrder(root);

    return 0;

}