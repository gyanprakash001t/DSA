#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val):data(val), next(nullptr){};
};

void traversal(Node* head)
{   
    int count =0;
    Node* temp = head;
    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp= temp->next;
        count++;
    }
    cout<<endl;
    cout<<"No of node: "<<count<<endl;
    return;
}

int main()
{
    // linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next  =new Node(3);
    head->next->next->next = new Node(7);


    // print the traversal
     traversal(head);

}