// representation of BINARY TREE

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node*left;
    struct Node*right;
    // a constructor is a special function inside a class that automatically runs  when an object is created
    Node (int val)
    {
        data=val;
        left=right=nullptr;
    }
};

int main()
{
    struct Node* root = new Node(1);
    root->left =new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    return 0;
}