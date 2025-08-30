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

Node* arrangeOddEvenM1(Node* head)
{
    if (!head || !head->next) return head;

    Node* temp = head;
    list<int>list;
    while(temp)
    {
        list.push_back(temp->data);
        if (!temp->next) break;
        temp = temp->next->next;
    }
    
    temp = head->next;
    while(temp)
    {
        list.push_back(temp->data);
        if (!temp->next) break;
        temp = temp->next->next;
    }

    temp = head;
    for( auto it :list)
    {
    temp->data = it;
    temp= temp->next;
    }

    return head;
}

Node* arrangeOddEvenM2(Node*head )
{
    if (!head || !head->next) return head;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
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

int main()
{
    Node* head1 = nullptr;
   
    // create first list: 2 -> 4 -> 3 ->6 ->5 ->8
    head1 = insertEnd(head1, 2);
    head1 = insertEnd(head1, 4);
    head1 = insertEnd(head1, 3);
    head1 = insertEnd(head1, 6);
    head1 = insertEnd(head1, 5);
    head1 = insertEnd(head1, 8);

    // Node* result  = arrangeOddEvenM2(head1);
    Node* resultM1 =  arrangeOddEvenM1(head1);
    printLL(resultM1 );



   
    return 0;
}

