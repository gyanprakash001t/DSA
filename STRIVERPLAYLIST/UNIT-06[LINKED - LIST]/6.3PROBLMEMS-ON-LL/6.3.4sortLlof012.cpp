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

// brute  --> data replacement 

Node* sortLlOf012(Node* head)
{
    if(!head || !head->next) return head;
    Node* temp = head; 
    int cntZeros=0;
    int cntOnes=0;
    int cntTwos =0;
    while(temp)
    {
        if(temp->data == 0) cntZeros++;
        if(temp->data == 1) cntOnes++;
        if(temp->data ==2) cntTwos++;
        temp = temp->next;
    }

    temp = head;
    while(cntZeros)
    {
        temp->data =0;
        temp= temp->next;
        cntZeros--;
    }
    while(cntOnes)
    {
        temp->data=1;
        temp= temp->next;
        cntOnes--;
    }
     while(cntTwos)
     {
        temp->data = 2;
        temp = temp->next;
        cntTwos--;
     }

     return head;

}

//in one pass
Node* sortOf012Optimised(Node* head)
{
    Node* temp =head;

    Node* zeroHead = new Node(-1);
    Node* zero = zeroHead;

    Node* oneHead = new Node(-1);
    Node* one = oneHead;

    Node* twoHead = new Node(-1);
    Node* two = twoHead;

    while(temp)
    {
        if(temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
           
        }
        else if(temp->data == 1)
        {
            one->next = temp;
            one = temp;
            
        }
        else
        {
            two->next= temp;
            two= temp;
           

        }
         temp=temp->next;

    }

    // linking the heads and tails

    
   zero->next  = oneHead->next?oneHead->next: twoHead->next;
   one->next=twoHead->next;
   two->next = nullptr;

   temp =zeroHead->next;
   return temp;

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
   
    // create first list: 1 -> 0 -> 1 ->1 ->2 ->0->2->1
    head1 = insertEnd(head1, 1);
    head1 = insertEnd(head1, 0);
    head1 = insertEnd(head1, 1);
    head1 = insertEnd(head1, 2);
    head1 = insertEnd(head1, 0);
    head1 = insertEnd(head1, 2);
    head1 = insertEnd(head1, 1);
    printLL(head1);
    cout<<endl;
    // Node* result = sortLlOf012(head1);
    Node* result = sortOf012Optimised(head1);
    printLL(result);
    return 0;
}