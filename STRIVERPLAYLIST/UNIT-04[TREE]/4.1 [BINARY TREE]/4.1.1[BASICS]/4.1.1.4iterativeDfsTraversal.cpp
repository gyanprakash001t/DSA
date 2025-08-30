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

vector<int> iterativePreOrder(TreeNode* root)
{
    vector<int>preOrder;
    if(root == NULL) return preOrder ;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();
        preOrder.push_back(node->data);
        if(node->right != NULL) st.push(node->right);
        if(node->left != NULL) st.push(node->left);

    }
    return preOrder;

}

// iterative inorder
vector<int> iterativeInorder(TreeNode* root)
{
    stack<TreeNode*> st;
    TreeNode* node =root;
    vector<int>inOrder;
    while(true)
    {
        if (node != NULL)
        {
            st.push(node);
            node=node->left;
        }
        else
        {
            if(st.empty() == true) break;
            node= st.top();
            st.pop();
            inOrder.push_back(node->data);
            node = node->right;
        }
    }
    return inOrder;
}


// iterative Post-Order
// using 2 stack
 vector<int> iterativePostOrder(TreeNode* root)
 {
    vector<int>postOrder;
    stack<TreeNode*> st1;
    stack<TreeNode*>st2;
    st1.push(root);
    while(! st1.empty())
    {
        root =st1.top();
        st1.pop();
        st2.push(root);
        if (root->left != NULL)  st1.push(root->left);
        if (root ->right != NULL) st1.push(root->right);

    }

    while(! st2.empty())
    {
        postOrder.push_back(st2.top()->data);
        st2.pop();
    }

    return postOrder;

 }

 // iterative post order using single stack

 vector<int> iterativePostOrderUsingSingleStack(TreeNode* root)
 {
    vector<int> postOrder;
    TreeNode* curr =root;
    stack<TreeNode*> st;
    while(curr!= NULL || !st.empty())
    {
        if(curr != NULL)
        {
            st.push(curr);
            curr =curr->left;
        }
        else
        {
          TreeNode* temp =  st.top()->right;
          if(temp == NULL)
          {
            temp =st.top();
            st.pop();
            postOrder.push_back(temp->data);

            while(!st.empty() && temp == st.top()-> right)
            {
            temp = st.top();
            st.pop();
            postOrder.push_back(temp->data);
            }
          
          }
          else
          {
            curr =temp;
          }
        }
    }
    return postOrder;
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

    // preOrder
    vector<int> iterativePreOrderCall = iterativePreOrder(root);
    cout<<"pre-Order traversal"<<endl;
    for(auto it : iterativePreOrderCall)
    {
        cout<<it<<" ";
    }
    cout<<endl;
  

    // In-Order

    vector<int>iterativeInOrderCall = iterativeInorder(root);
    cout<<"In-Order traversal"<<endl;
    for(auto it : iterativeInOrderCall)
    {
        cout<<it<<" ";
    }
    cout<<endl;

    // Post-Order

    vector<int>iterativepostOrderCall = iterativePostOrder(root);
    cout<<"Post-Order traversal"<<endl;
    for(auto it : iterativepostOrderCall)
    {
        cout<<it<<" ";
    }
        cout<<endl;

    vector<int>iterativePostOrderCall2= iterativePostOrderUsingSingleStack(root);
    cout<<"Post-Order traversal2"<<endl;
    for(auto it : iterativePostOrderCall2)
    {
        cout<<it<<" ";
    }

    return 0;
} 