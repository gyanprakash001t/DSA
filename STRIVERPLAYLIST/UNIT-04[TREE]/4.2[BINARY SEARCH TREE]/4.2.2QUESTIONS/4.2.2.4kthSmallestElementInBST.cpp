#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int data): val(data), left(NULL), right(NULL) {}
};

// Inorder traversal with counter
int kthSmallest(Node* root, int k) {
    stack<Node*> st;
    Node* curr = root;

    while (curr != NULL || !st.empty()) {
        // Go left as much as possible
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        k--; // visiting one node

        if (k == 0) return curr->val; // found kth smallest

        curr = curr->right; // move to right subtree
    }
    return -1; // if k > number of nodes
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

    int k = 3;
    cout << k << "rd smallest = " << kthSmallest(root, k) << endl;

    return 0;
}
