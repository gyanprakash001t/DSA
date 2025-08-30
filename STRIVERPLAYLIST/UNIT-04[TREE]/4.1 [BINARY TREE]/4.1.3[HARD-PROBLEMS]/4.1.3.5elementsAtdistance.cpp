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

 void markParents(Node* root, unordered_map<Node*,Node*>& parent_Track)
 {
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        if(curr-> left) 
        {
            parent_Track[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr-> right) 
        {
            parent_Track[curr->right] = curr;
             q.push(curr->right);
        }
    }
 }

 vector<int>elementsAtDistanceK(Node* root, Node* target, int k)
 {
    unordered_map<Node*, Node*>parentMapper;
    markParents(root,parentMapper);
    unordered_map<Node*,bool>visited;
    queue<Node*>q;
    q.push(target);
    visited[target] = true;
    int currLevel= 0;
    while(!q.empty())
    {
    
        int size = q.size();
        if(currLevel == k) break;

        for(int i=0;i<size;i++)
        {

        Node* curr = q.front();
        q.pop();
        if(curr->left && !visited[curr->left])
        {
            q.push(curr->left);
            visited[curr->left] = true;
        }
        if(curr->right && !visited[curr->right])
        {
            q.push(curr->right);
            visited[curr->right] = true;
            
        }

        if(parentMapper[curr] && !visited[parentMapper[curr]])
        {
           q.push(parentMapper[curr]);
           visited[parentMapper[curr]] = true;
        }

        }

        currLevel++;
    }
    vector<int>result;
    while(!q.empty())
    {
        Node* curr= q.front();
        q.pop();
        result.push_back(curr->data);
    }
    return result;
        
 }

 int main()
 {
    Node*  root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right= new Node(8);

    vector<int> elementsatDistancKCall = elementsAtDistanceK(root,root->left,2);
    for(auto it:elementsatDistancKCall )
    {
        cout<<it<<" ";
    }

    return 0;
 }

