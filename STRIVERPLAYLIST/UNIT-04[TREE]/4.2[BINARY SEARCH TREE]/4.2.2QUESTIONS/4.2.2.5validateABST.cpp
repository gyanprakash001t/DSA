#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int data): val(data), left(NULL), right(NULL) {}
};

// Utility function
bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
    if (root == NULL) return true;

    if (root->val <= minVal || root->val >= maxVal) return false;

    return isBSTUtil(root->left, minVal, root->val) &&
           isBSTUtil(root->right, root->val, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    /*
             10
            /  \
           5    15
          / \   / \
         2   7 12 20
    */
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    if (isBST(root))
        cout << "The tree is a BST\n";
    else
        cout << "The tree is NOT a BST\n";

    return 0;
}
