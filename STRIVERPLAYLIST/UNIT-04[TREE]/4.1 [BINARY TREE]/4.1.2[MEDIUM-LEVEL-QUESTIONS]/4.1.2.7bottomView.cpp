#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int val;
    struct Node* left;
    struct Node* right;

    Node(int data)
    {
        val=data;
        left= NULL;
        right =NULL;
    }
};

vector<int> bottomView(Node* root)
{
    vector<int> ans;
    if(root==NULL) return ans;
    map<int, int> mpp ;  // vertical-Line , node
    queue<pair<Node*, int>>q;   // node ,line
    q.push({root, 0});

    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;
        mpp[line] = node->val;
        
      

        if(node->left)
        {
            q.push({node->left, line-1});
        }
        if (node->right)
        {
            q.push({node->right, line+1});
        }

    }

    for(auto it: mpp)
    {
        ans.push_back(it.second);
    }
    return ans;


}

int main()
{
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left =new Node(6);
    root->right->right = new Node(7);

    vector<int> topViewCall = bottomView(root);
    for(auto it: topViewCall)
    {
        cout<<it;
    }
    return 0;
}

