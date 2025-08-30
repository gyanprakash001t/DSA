#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function
Node* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd,  unordered_map<int, int>& inMap)
                      
{
    if (preStart > preEnd || inStart > inEnd) return NULL;

    // First element in preorder is the root
    Node* root = new Node(preorder[preStart]);

    // Find root position in inorder
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;

    // Build left and right subtrees
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,  inorder, inStart, inRoot - 1, inMap);                         
    root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);  

    return root;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) 
    {
        inMap[inorder[i]] = i;
    }
    return buildTreeHelper(preorder, 0, preorder.size() - 1,  inorder, 0, inorder.size() - 1, inMap);
                          
}

// Utility: print tree (postorder)
void printPostorder(Node* root) 
{
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Node* root = buildTree(preorder, inorder);

    cout << "Postorder Traversal of constructed tree: ";
    printPostorder(root);
    cout << endl;

    return 0;
}
