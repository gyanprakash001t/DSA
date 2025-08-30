                           
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>

using namespace std;


struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreePostIn(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, map<int, int>& hm)
{
   if (ps > pe || is > ie) 
   {
      return NULL;
   }
   
    TreeNode* root = new TreeNode(postorder[pe]);

     // Find the index of the root
    int inRoot = hm[postorder[pe]];
        
    // Number of nodes in the left subtree
    int numsLeft = inRoot - is; 
      
    root->left = buildTreePostIn(inorder, is, inRoot - 1, postorder,  ps, ps + numsLeft - 1, hm);
    root->right = buildTreePostIn(inorder, inRoot + 1, ie, postorder, ps + numsLeft, pe - 1, hm);
           
    return root;       
       
       
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
{
   if (inorder.size() != postorder.size()) 
        {
            return NULL;
        }

        map<int, int> hm;
        for (int i = 0; i < inorder.size(); i++) 
        {
            hm[inorder[i]] = i;
        }

        
        return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0,postorder.size() - 1, hm);     
            
}


void printInorder(TreeNode* root) {
    if (!root) {
        return;
    }
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};

    TreeNode* root = buildTree(inorder, postorder);

    cout << "Inorder of Unique Binary Tree Created: " << endl;
    printInorder(root);  // if it is same as the  given inorder then  we have did it correctly
    cout << endl;

    return 0;
}
