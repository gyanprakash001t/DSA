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


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int>pathFind = path(root,4);
    for(auto it:pathFind)
    {
        cout<<it<<" ";
    }

    return 0;
}