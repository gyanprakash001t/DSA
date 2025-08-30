#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int val;
    Node* left;
    Node* right;
    // constructor
    Node(int data)
    {
        val = data;
        left = right= nullptr;
    }
};

void parentMapper(Node* root, unordered_map<Node*,Node*>&parentTracker)
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
       
        int size = q.size();
        bool nextLevel = false;
        for(int i=0;i<size;i++)
        {
            Node* curr =  q.front();
            q.pop();
            if(curr->left)parentTracker[curr->left]= curr;
            if(curr->right)parentTracker[curr->right]= curr;

        }

    }
    return;

}

int miminmumTimeToBurn(Node* root, Node* start)
{
    unordered_map<Node*,Node*>parentTracker;
    parentMapper(root, parentTracker);
    int time =0;
    queue<Node*>q;
    unordered_map<Node*, bool>visited;
    q.push(start);
    visited[start]=true;
    while(!q.empty())
    {
        int size= q.size();
        bool nextLevel;
        for( int i=0;i<size;i++)
        {
            Node* curr = q.front();
            q.pop();

            if(curr->left && !visited[curr->left])
            {
                nextLevel = true;
                q.push(curr->left);
                visited[curr->left] =true;
            }
            if(curr->right && !visited[curr->right])
            {
                nextLevel = true;
                q.push(curr->right);
                visited[curr->right] =true;
            }
            if(parentTracker[curr] && !visited[parentTracker[curr]])
            {
                nextLevel = true;
                q.push(parentTracker[curr]);
                visited[parentTracker[curr]] =true;
            }
        }
        if(nextLevel) time++;


    }
    return time-1;


}
int main()
{
    //BT
    Node*  root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right= new Node(8);

    int mimimumTimeToBurnCalculation = miminmumTimeToBurn(root, root->left);
    cout<<"mimimum time ="<<mimimumTimeToBurnCalculation;
    return 0;
}
