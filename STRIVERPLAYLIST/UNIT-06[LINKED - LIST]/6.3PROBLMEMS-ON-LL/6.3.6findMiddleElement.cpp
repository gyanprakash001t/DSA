#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node* next;
    Node(int val): data(val), next(nullptr){}

};

// Insert at end
Node* insertEnd(Node* head, int val)
 {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next)
     {
         temp = temp->next;   
     }
    temp->next = newNode;
    return head;
   
}

void printLL(Node* head)
{
    Node* temp = head;
    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}

Node* middleElement(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
     }
     return slow;
}

int main()
{
    Node* head1 =nullptr;

    // create first list: 2 -> 4 -> 3 ->6 ->5 ->8
    head1 = insertEnd(head1, 2);
    head1 = insertEnd(head1, 4);
    head1 = insertEnd(head1, 3);
    head1 = insertEnd(head1, 6);
    head1 = insertEnd(head1, 5);
    head1 = insertEnd(head1, 8);

    printLL(head1);
    cout<<endl;
    Node* result = middleElement(head1);
    printLL(result);
    
    return 0;
}