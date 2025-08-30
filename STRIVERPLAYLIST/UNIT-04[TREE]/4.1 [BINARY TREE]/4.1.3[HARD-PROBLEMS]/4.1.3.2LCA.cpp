#include<bits/stdc++.h>
using namespace std;

struct Node 
{
       int data;
       struct Node* left;
       struct Node* right;
       Node( int val)
       {
        data=val;
        left=nullptr;
        right=nullptr;
       }

 };

 bool getPath( Node* root, vector<int>&arr, int x)
{
    if (!root) return false;
    arr.push_back(root->data);
    if(root->data == x) return true;

    if(getPath(root->left, arr, x) || getPath(root->right,arr,x)) return true;

    arr.pop_back();
    return false;

}

vector<int>path(Node* root, int x )
{
    vector<int>arr;
    if(root == nullptr) return arr;
    getPath(root, arr, x);
    return arr;
}

 void LCA (vector<int>&path1, vector<int>&path2)
 {
    int index = 0;
    while (index  < min(path1.size()-1, path2.size()-1))  
    {
        if (path1[index + 1] != path2[index + 1])
        {
            cout << path1[index] << endl; // print LCA  
        }
        index++;

    }

 }

 // optimal approach - it uses single traversal  and  half of memory compared to last one cause we aren't storing the bot the paths

 Node* LCAoptimised(Node*root, int p, int q )
 {
    // base case
    if (root==NULL || root->data ==p || root->data == q)
    {
        return root;
    }

    // progress
    Node* left = LCAoptimised(root->left,p,q);
    Node* right =LCAoptimised(root->right, p,q);

    // result
    if(left == NULL)
    {
        return right;
    }
    else if(right == NULL)
    {
        return left;
    }
    else
    {
        return root; // if none of  them are null  then we got our answer

    }
 }


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    vector<int>pathFind1 = path(root,4);
    vector<int>pathFind2 = path(root,7);
    LCA(pathFind1, pathFind2);
    // cout<<endl;
    Node* LCAoptimiseCall = LCAoptimised(root,4,7);
    cout<<LCAoptimiseCall->data;



    

   
    

    return 0;
}