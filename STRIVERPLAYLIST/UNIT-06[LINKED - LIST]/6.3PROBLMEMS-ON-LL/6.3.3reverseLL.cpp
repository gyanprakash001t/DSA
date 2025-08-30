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

Node* reverseLlIterative(Node* head)
{
    if(!head || ! head->next)  return head;
     
    Node* temp = head;
    Node* tempMinusOne = nullptr;
    Node* tempNext = nullptr;
     while(temp)
     {
        tempNext= temp->next;
        temp->next = tempMinusOne;
        tempMinusOne= temp;
        temp = tempNext;

     }
     return tempMinusOne;
}

Node* reverseLlrecursive(Node* head, Node* tempMinusOne , Node* tempNext )
{
    Node* temp = head;
    
    

    if(temp == nullptr)return tempMinusOne;
    tempNext= temp->next;
    temp->next = tempMinusOne;
    tempMinusOne= temp;
    temp = tempNext;
    return reverseLlrecursive(temp,tempMinusOne,tempNext);
    
    

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
    // Node* resultM1 =  reverseLlIterative(head1);
    Node* resultM2 =  reverseLlrecursive(head1,nullptr,nullptr);
    printLL(resultM2);



   
    return 0;
}

