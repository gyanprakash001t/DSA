#include<bits/stdc++.h>
using namespace std;

struct TreeNode 
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    // constructor
    TreeNode(int data)
    {
        val=data;
        left =nullptr;
        right =nullptr;

    }
};

vector<vector<int>>bfsTraversalsTogether(TreeNode* root)
{

    vector<vector<int>>traversal;
    vector<int>pre,in,post;
    stack<pair<TreeNode*, int>>st;
    st.push({root,1});

    if(root ==NULL) return traversal;

    while(!st.empty())
    {
        auto it =st.top();
        st.pop();

        // preorder
        if(it.second ==1)
        {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->left != NULL)
            {
                st.push({it.first->left,1});
            }
        }
        //inorder
        else if(it.second==2)
        {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }

        }
        //postOrder
        else
        {
            post.push_back(it.first->val);

        }

    }
    traversal.push_back(pre);
    traversal.push_back(in);
    traversal.push_back(post);
    return traversal;

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

    vector<vector<int>> traversalCall = bfsTraversalsTogether(root);
    for(auto it:traversalCall)
    {
       for(auto it1 :it)
       {
        cout<<it1<<" ";
       }
       cout<<endl;
    }
    return 0;
}