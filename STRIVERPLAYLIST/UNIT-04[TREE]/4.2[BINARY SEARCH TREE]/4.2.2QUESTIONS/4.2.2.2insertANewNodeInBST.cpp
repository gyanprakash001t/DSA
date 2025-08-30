#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int data):val(data), left(NULL),right(NULL){}
};

Node* insertNodeIntoBST(Node* root, int val)
{
    if(root == NULL) return new Node(val);
    Node* curr = root;
    
    while(true)
    {
        if(curr->val<val)
        {
            if(curr->right != NULL)
            {
                curr= curr->right;
            }
            else
            {
                curr->right = new Node(val);
                break;
            }
        }

        else
        {
            if (curr->left != NULL)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = new Node(val);
                break;

            }

        }

    }
    return root;

}


int main()
{
    // BST
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    Node* modifiedTreeRoot = insertNodeIntoBST(root,22);
    cout<<modifiedTreeRoot->val;
    return 0;
}