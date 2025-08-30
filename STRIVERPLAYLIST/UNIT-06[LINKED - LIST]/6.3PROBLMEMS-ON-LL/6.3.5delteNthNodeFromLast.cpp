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
// brute-method TC:O(2n)
// we can find number of nodes  then  delete the   required node

//optimised  TC:O(n)
//
// Node* deleteNthNodeFromEnd(Node* head, int n)
// {
//     Node* dummy = new Node(-1);  // dummy node to simplify head deletion
//     dummy->next = head;

//     Node* first = dummy;
//     Node* second = dummy;
   
//       // Move first n+1 steps ahead
//     for(int i = 0; i <= n; i++) {
//         if(first == nullptr) return head; // n > length of list
//         first = first->next;
//     }
//     // we'll move both 
//     while(first)
//     {
//         second= second->next;
//         second=second->next;
//     }
//     Node* toBeDeleted = second->next;
//     second->next =second->next->next;
//     delete toBeDeleted;

//     Node* newHead = dummy->next;
//     delete dummy;  // cleanup
//     return newHead;
// }


Node* deleteNthNodeFromEnd(Node* head, int n) {
    Node* dummy = new Node(-1);  // dummy node to simplify head deletion
    dummy->next = head;

    Node* first = dummy;
    Node* second = dummy;

    // Move first n+1 steps ahead
    for(int i = 0; i <= n; i++) {
        if(first == nullptr) return head; // n > length of list
        first = first->next;
    }

    // Move both until first reaches end
    while(first) {
        first = first->next;
        second = second->next;
    }

    // Delete node
    Node* toBeDeleted = second->next;
    second->next = second->next->next;
    delete toBeDeleted;

    Node* newHead = dummy->next;
    delete dummy;  // cleanup
    return newHead;
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
    Node* result = deleteNthNodeFromEnd(head1,3);
    printLL(head1);
    return 0;
}