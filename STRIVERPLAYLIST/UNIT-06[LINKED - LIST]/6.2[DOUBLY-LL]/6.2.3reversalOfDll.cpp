#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node(int val): data(val),next(nullptr),prev(nullptr){}
};

Node* reverseLinkedListM1(Node* head)
{
    stack<int> st;
    Node* temp= head;

    while( temp != nullptr)
    {
        st.push(temp->data);
        temp= temp->next;

    }
    
    temp = head;
   while(!st.empty())
    {
        temp->data= st.top();
        st.pop();
        temp=temp->next;
    }

    return head;
}

Node* reverseLinkedListM2(Node* head)
{
    Node* curr= head;
    Node* temp = nullptr;

    if(curr  == nullptr || curr->next == nullptr ) return curr;

    while(curr != nullptr)
    {
         temp = curr->prev;
         curr->prev  = curr->next;
         curr->next = temp;
         

         // next to   node
         curr= curr->prev;
    }
     if( temp != nullptr)
     {
        head=  temp->prev;
     }
 
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
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev =head->next;
    head->next->next->next =new Node(1);
    head->next->next->next->prev =head->next->next;

    // Node* reverseLinkedListM1Call = reverseLinkedListM1(head);
    Node* reverseLinkedListM2Call = reverseLinkedListM2(head);
    printLL(reverseLinkedListM2Call);



    return 0;
}