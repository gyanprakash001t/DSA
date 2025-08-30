// a balance biary  tree is BT where the height difference  b/w left and right subtree at evry node is atmost 1

#include<bits/stdc++.h>
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
int maxDepth(TreeNode* root)
{
    if(root == NULL) return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1+max(lh,rh);
}


// brute solution TC :O(n*n)

bool check(TreeNode* root)
{
    if(root == NULL) return true;
    int Lh =maxDepth(root->left);
    int Rh =maxDepth(root->right);
    if(abs(Lh-Rh)>1)return false;
    bool left = check(root->left);
    bool right = check(root->right);
    if (!left || ! right) return false;
    return true;
}

// optimal solution --it will return height if treee is balanced otherwise -1


int check2(TreeNode* root)
{
    if(root == NULL) return 0;
    int Lh = check2(root->left);
    int Rh = check2(root->right);
    if(abs(Lh-Rh)>1)return -1;
    if(Lh == -1 && Rh == -1) return -1;
    return 1+ max(Lh,Rh);
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

    int ans1 = check(root);
    cout<<ans1<<endl;
    int ans2 = check2(root);
    cout<<ans2<<endl;
    return 0;
}

