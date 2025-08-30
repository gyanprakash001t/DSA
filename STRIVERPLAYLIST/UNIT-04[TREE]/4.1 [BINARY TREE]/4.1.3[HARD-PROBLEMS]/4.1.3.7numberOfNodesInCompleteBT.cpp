#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

  int findHeightLeft(TreeNode* node) 
    {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }

   int findHeightRight(TreeNode* node) 
    {
        int height = 0;
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }

int countNodes(TreeNode* root)
 {
      
        if (root == NULL) 
        {
            return 0;
        }
  
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);
        
       
        if (lh == rh) 
        { 
        return (1 << lh) - 1; 
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
 }
    
    
  
  
  



int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

 
    
    int totalNodes = countNodes(root);

    
    cout << "Total number of nodes in the Complete Binary Tree: "
    << totalNodes << endl;



    return 0;
}
                                