#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
     int data;
     TreeNode* left;
     TreeNode* right;
    // constructor
    TreeNode(int val)
    {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

 


bool isSymmetricFind(TreeNode* left, TreeNode* right)
{
    if(left ==NULL || right== NULL)
    {
        return (left==right) ;
    }

    if(left->data != right->data)
    {
        return false;
    }

    return isSymmetricFind(left->left , right->right) &&  isSymmetricFind(left->right, right->left);
}

bool isSymmetric(TreeNode* root)
{
    return (root== NULL|| isSymmetricFind(root->left, root->right));
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left =new  TreeNode(3);
    root->right ->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    bool  isSymmetricCall = isSymmetric(root);
    cout<<isSymmetricCall;



    return 0;
}