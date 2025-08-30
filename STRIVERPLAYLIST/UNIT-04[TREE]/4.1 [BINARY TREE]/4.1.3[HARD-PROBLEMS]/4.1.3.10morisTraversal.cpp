#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

// morrisTraversal sc:O(1);

vector<int>getInOrder(Node* root)
{
    vector<int>inOrder;
    Node* curr = root;
    while(curr != NULL )
    {
        if(curr->left == NULL)
        {
            inOrder.push_back(curr->val);
            curr= curr->right;
        }
        else
        {
            Node* prev = curr->left;
            while(prev->right && prev->right != curr)
            {
                prev= prev->right;  // rightmost node in left subtree
            }

            if(prev->right == NULL)
            {
                prev->right = curr; //  directed to the root  when rightmost start pointing null
                curr = curr->left;  // now we can move left from the curr ... before moving to the left we nust need to  direct the rightmost to the root;
            }
            else
            {
                prev->right = NULL;
                inOrder.push_back(curr->val);
                curr= curr->right;
            }
        }
    }
    return inOrder;
}

int main()
{
    // tree
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    vector<int>getInOrderMorisTraversal = getInOrder(root);
    for(auto  it:getInOrderMorisTraversal )
    {
        cout<<it<<" ";
    }


}