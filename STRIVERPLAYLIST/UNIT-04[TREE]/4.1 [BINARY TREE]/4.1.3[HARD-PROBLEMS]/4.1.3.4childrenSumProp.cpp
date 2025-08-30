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


 void changeTree(Node* root)
{
    if (!root) return;
    if (!root->left && !root->right) return; // leaf

    int child = 0;
    if (root->left) child += root->left->data;
    if (root->right) child += root->right->data;

    if (child < root->data)
    {
        if (root->left) root->left->data = root->data;
        if (root->right) root->right->data = root->data;
    }
    else
    {
        root->data = child; // important in some cases
    }
//Verdict
// Correctness → Removing else will not break correctness for any edge case. ✅
// Efficiency → Keeping else makes it more efficient by reducing unnecessary recursive corrections.

    changeTree(root->left);
    changeTree(root->right);

    int leftVal = root->left ? root->left->data : 0;
    int rightVal = root->right ? root->right->data : 0;
    root->data = leftVal + rightVal;
}

int main()
{
    Node*  root = new Node(1);
    root->left = new Node(7);
    root->right = new Node(3);
    root->left->left = new Node(8);
    root->right->right = new Node(4);

    changeTree(root);
}
