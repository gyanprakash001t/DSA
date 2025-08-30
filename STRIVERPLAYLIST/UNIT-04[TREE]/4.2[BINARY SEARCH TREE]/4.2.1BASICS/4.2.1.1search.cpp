#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) {
    val = x;
    left = right = nullptr;
    }
};

// Recursive 
Node* searchBST(Node* root, int key)
 {
    //base case
    if (root == nullptr || root->val == key)
    return root;  

    // process
    if (key < root->val)
    {
        return searchBST(root->left, key);
    }
    else
    {
        return searchBST(root->right, key);
    }
    
}

// Iterative 
Node* searchBSTIter(Node* root, int key)
 {
    while (root != nullptr && root->val != key) 
    {
        if (key < root->val)
        root = root->left;
        else
        root = root->right;
    }
    return root; 
}

int main() {

    //BST
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);


    int key = 7;
    Node* result = searchBST(root, key);

    if (result != nullptr)
    cout << "Found: " << result->val << endl;
    else
    cout << "Not Found" << endl;

    return 0;
}
