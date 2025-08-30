#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

// this is for adding members to the list or you can say insertion at end
Node* insertAtEnd(Node*head,int data){
 Node* newNode = new Node;  
 newNode->data=data;

 // If the list is empty
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;  // Point to itself to make it circular
    }
 
 else{
    // traverse to the last node
    Node*ptr=head;
    while(ptr->next!=head){
       ptr=ptr->next;
    }
    
    ptr->next=newNode;
    newNode->next=head;
 }
 return head;

};

//deletion of a node from circular linked list
Node* deleteNode(Node* head, int index){
    Node* temp = head;
    for(int i=0;i<index-1;i++){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    // delete temp->next;
     return head;
};

// Function to traverse and display the circular linked list
void traverseCircularList(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }
    
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
};

// Function to free the entire circular linked list
void freeCircularLinkedList(Node* &head) {
    if (head == nullptr) {
        // List is empty, nothing to free
        return;
    }
    
    if (head->next == head) {
        // List contains only one node
        delete head;
        head = nullptr;
        return;
    }
    
    Node* temp = head;
    Node* nextNode = nullptr;
    
    do {
        nextNode = temp->next;
        delete temp;
        temp = nextNode;
    } while (temp != head);
    
    head = nullptr;  // Set head to nullptr after freeing all nodes
}

int main(){

    // creation of circular linked list;
    Node* head= nullptr;

   // Insert nodes at the end  // this is for creation of linkedlist
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 50);

    // Traverse and display the circular linked list
    cout << "Circular Linked List: ";
    traverseCircularList(head);

    //node deletion
    head=deleteNode(head,1);
    cout<<"linked list after deletion";
    traverseCircularList(head);

    // Free the circular linked list
    freeCircularLinkedList(head);

    // Check if the list is successfully freed
    cout << "Circular linked list after deletion:" << endl;
    traverseCircularList(head);

    return 0;
}