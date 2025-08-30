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

vector<int>sideView(TreeNode* root)
{
vector<int>ans;
if(root==NULL) return ans;

queue<TreeNode*>q; 
q.push(root);

while(!q.empty())
{
    int size=q.size();
    vector<int> level;
    for(int i=0;i<size;i++)
    {
        TreeNode* node =q.front();
        q.pop();
        if (node->left != NULL) q.push(node->left);
        if (node->right !=NULL) q.push(node->right);
        level.push_back(node->data);
 
    }
    // ans.push_back(level.front());  // left view
    ans.push_back(level.back()); // right view
}
return ans;

}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left =new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<int> sideViewCall=sideView(root);
    for(auto it:sideViewCall)
    {
        cout<<it<<" ";
        
        
    }
    return 0;
}