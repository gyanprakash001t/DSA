#include <iostream>
#include <vector>

using namespace std;


    struct Node
    {
        int data;
        Node* left;
        Node* right;
        Node(int val) 
        {
            data =val;
            left= NULL;
            right=NULL;
        }
    };

    bool isLeaf(Node* root) 
    {
        return (root->left == NULL  && root->right == NULL);
    }


    void addLeftBoundary(Node* root, vector<int>& res)
     {
        Node* curr = root->left;
        while (curr != NULL) 
        {
           
            if (!isLeaf(curr)) {
                res.push_back(curr->data);
            }

          
            if (curr->left != NULL) 
            {
                curr = curr->left;
            } 
            else 
            {
                curr = curr->right;
            }
        }

      }

 
    void addRightBoundary(Node* root, vector<int>& res) 
    {
        Node* curr = root->right;
        vector<int> temp;
        while (curr != NULL) 
        {
           
            if (!isLeaf(curr)) 
            {
                temp.push_back(curr->data);
            }

            
            if (curr->right) 
            {
                curr = curr->right;
            } 
            else
            {
                curr = curr->left;
            }
        }
       
        for (int i = temp.size() - 1; i >= 0; --i) 
        {
            res.push_back(temp[i]);
        }
    }

   
    void addLeaves(Node* root, vector<int>& res) {
        
        if (isLeaf(root)) 
        {
            res.push_back(root->data);
            return;
        }

        if (root->left  != NULL) 
        {
            addLeaves(root->left, res);
        }

        if (root->right !=NULL) 
        {
            addLeaves(root->right, res);
        }
    }

    
    vector<int> traverseBoundary(Node* root) 
    {
        vector<int> res;
        if (root == NULL) 
        {
            return res;
        }
        
        if (!isLeaf(root)) 
        {
            res.push_back(root->data);
        }

        
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }



    void printResult(const vector<int>& result) 
    {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    }

int main() {
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

 

    vector<int>result =traverseBoundary(root);
    
    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);
    

    return 0;
}