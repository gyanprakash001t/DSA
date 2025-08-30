#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int val;
    Node* left;
    Node* right;
    // constructor
    Node(int data)
    {
        val = data;
        left = right= nullptr;
    }
};


int findCeil(Node* root, int key)
{
    int ceil =-1;
    while(root)
    {
        if(root->val == key)
        {
            ceil = root->val;
            return  ceil;
        }
        if(key > root->val)
        {
            root = root->right;
        }
        else
        {
            ceil= root->val;
            root=  root->left;

        }

    }
    return ceil;

}

int main()
{
    //BST
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    int ceil = findCeil(root, 11);
    cout<<ceil;

    return 0;
}