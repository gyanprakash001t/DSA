// you are  given with a binary  tree and have to check whether is  it a max heap ?

#include<bits/stdc++.h> 
using namespace std;
struct Node
{
    int data;
    struct Node*left;
    struct Node*right;
    // constructor
    Node (int val)
    {
        data=val;
        left=right=nullptr;
    }
};

int node_cnt(Node* root)
{
    if(root == nullptr) return 0;
    return  1+ node_cnt(root->left) + node_cnt(root->right);
}

bool is_complete(Node* root, int index, int total_cnt)
{
    // base  case
    if(root == nullptr) return true;
    if(index >= total_cnt) return false;
    
    return is_complete(root->left, 2*index+1, total_cnt) && is_complete(root->right, 2*index+2, total_cnt);
}

bool is_max_heap(Node* root)
{

    //leaf node
    if(root->left == nullptr && root->right == nullptr) return true;

    // only left child 
    if(root->right == nullptr)
    {
        return  ((root->data >= root->left->data) 
                &&( is_max_heap(root->left)));

    }
    else     // both child
    {
        if(root->data >= root->left->data && root->data >= root->right->data)  
        {
            return is_max_heap(root->left) &&
                   is_max_heap(root->right);
        }
        else
            return false;
    }

}

bool is_heap(Node* root)
{
    int total_cnt = node_cnt(root);
    return  is_complete(root, 0, total_cnt) && is_max_heap(root);
}



int main()
{
    struct Node* root = new Node(3);
    root->left =new Node(2);
    root->right = new Node(1);
    // root->left->left = new Node(0);
    root->left->right = new Node(0);
    cout<<is_heap(root);


    return 0;
}