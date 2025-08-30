// Problem Statement: Given a Binary Tree, return its maximum width. The maximum width of a Binary Tree is the maximum diameter among all its levels. The width or diameter of a level is the number of nodes between the leftmost and rightmost nodes

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

int maxWidth(Node* root)
{
    if(!root) return 0;
    int widht=0;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        int size = q.size();
        int idMin= q.front().second; // cause it will be the first  element of this level
        int first, last;           // to store the index of  first and last  element at the level respectively
        for(int i=0;i<size;i++)
        {
            int currId=q.front().second - idMin;    // so that we can have indexing from 0 at every level abd to stop overflow
            Node* node =q.front().first;
            q.pop();

            if(i==0) 
            {
                first= currId;
            }
            if(i==size-1)
            {
                last = currId;
            }
            if(node->left)q.push({node->left, 2*currId+1});
            if(node->right)q.push({node->right, 2*currId+2});
        }
        widht = max(widht,last-first+1);
    }
 return widht;

}

int main()
{
    Node*  root = new Node(1);
    root->left = new Node(7);
    root->right = new Node(3);
    root->left->left = new Node(8);
    root->right->right = new Node(4);

    int maxWidthCall = maxWidth(root);
    cout<<maxWidthCall;
    return 0;
}