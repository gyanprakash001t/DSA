# include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    // constructor
    TreeNode(int val)
    {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

int findLength(TreeNode* root)
{
    if(root == NULL) return 0;
    int lh = findLength(root->left);
    int rh = findLength(root->right);
    return 1+max(lh,rh);
}



// diameter = largest path in tree (it's not necessary to pass via  root)

// brute
int maxi=0;
int  findMax(TreeNode* root)
{
   
    if(root == NULL)
    {
        return 0;
    }
   int Lh= findLength(root->left);
   int Rh= findLength(root->right);
   maxi = max(maxi,Lh+Rh);
   findMax(root->left);
   findMax(root->right);
   return maxi;
}

// optimise

int findMax(TreeNode* root, int &diameter)
{
    if(root==NULL) return 0;
    int Lh=findMax(root->left,diameter);
    int Rh = findMax(root->right,diameter);
    diameter =max(diameter,Lh+Rh);
    return 1+max(Lh,Rh);
}

int diameterOfBinaryTree(TreeNode* root)
    {
        int diameter=0;
        findMax(root,diameter);
        return diameter;
    }


int main()
{
    // defn of tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left =new TreeNode(6);
    root->right->right = new TreeNode(7);


    int dbrute= findMax(root);
    cout<<dbrute<<endl;
    int doptimal = diameterOfBinaryTree(root);
    cout<<doptimal;


    
    return 0;
}