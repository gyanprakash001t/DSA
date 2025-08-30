// Problem Statement: Given a Binary Tree, return the Vertical Order Traversal of it starting from the Leftmost level to the Rightmost level. If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

#include<bits/stdc++.h>
using namespace std;

struct TreeNode 
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;

    TreeNode(int data)
    {
        val=data;
        left= NULL;
        right =NULL;
    }
};


vector<vector<int>> verticalTraversal(TreeNode* root)
{
    map<int,map<int,multiset<int>>> mpp;  // vertical, level,node
    queue<pair<TreeNode* , pair<int , int>>>q; // node , vertical, level
    q.push({root,{0,0}});

    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first; // node
        int x= p.second.first;  // vertical
        int y = p.second.second ;// level
        mpp[x][y].insert(node->val);

        if(node->left)
        {
            q.push({node->left,{x-1, y+1}});
        }

        if(node->right)
        {
            q.push({node->right,{x+1, y+1}});
        }

        
    }

    vector<vector<int>> ans;
    for(auto p : mpp)   //  iterating  vertical
    {
        vector<int>col;
        for( auto q: p.second)  // iteerating multiset of the vertical
        {
            col.insert(col.end(),q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }

    return ans;



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

    vector<vector<int>>verticalOrderView =  verticalTraversal(root);
    for(auto it: verticalOrderView)
    {
        for(auto it1 :  it)
        {
            cout<<it1<<" ";
        }
        
    }


    return 0;
}