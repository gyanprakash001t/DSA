#include <iostream>  // For standard I/O
 using namespace std;

struct Node {
    int data;
    Node* next;  // Pointer to the next node
};

void linkedlistTraversal(Node* ptr) {
    // cout<<"elements before any insertion \n";
    while (ptr != nullptr) {  // nullptr is the C++ equivalent of NULL
        cout << "Element is: " << ptr->data << endl;
        ptr = ptr->next;  // Move to the next node
    }
}

// Insertion at the beginning
 Node* insertionAtBeginnnging (Node*head,int data){   // insertion at beginning
    Node* newFirstNode=new Node();
    newFirstNode->data=data;
    newFirstNode->next=head;
    head=newFirstNode;
    return head;

} 

// Insertion at any index
Node*insertAtIndex(Node* head,int data,int index){

    //  if (index == 0) {  // If inserting at the beginning
    //     return insertionAtBeginnnging(head, data);
    // }

    Node* newNode=new Node();
    newNode->data=data;
    Node* temp=head;
    for(int i=0;i<index-1;i++){
        temp=temp->next;
    }
    newNode->next=temp->next; // abhi hmara node insert nhi hua h means node stored in temp node is (index-1)th node and isme next node ka addrees h which should newNode->next and then (index-1)th node me newnode ka address assign kr denge
    temp->next=newNode;
    return head;
}

// insert at end
Node*insertAtEnd(Node* head,int data){
    Node* lastNode =new Node();
    Node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=lastNode;
    lastNode->data=data;
    lastNode->next=nullptr;
    return head;
}

//insert after a node whose pointer is given
Node* insertAfterANode(Node* head,Node*node,int data){
Node* newNode=new Node();
newNode->data=data;
newNode->next=node->next;
node->next=newNode;
return head;
}

// Function to delete the entire linked list
// void deleteList(Node* head) {
//     Node* temp;
//     while (head != nullptr) {
//         temp = head;
//         head = head->next;
//         delete temp;
//     }
//     head = nullptr;  // Set the head to null after deletion to avoid dangling pointers
// }


int main() {
    // Pointers to nodes
    Node* head;
    Node* second;
    Node* third;
    Node* fourth;

    // Allocates memory for the nodes using 'new' operator in C++
    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list
    fourth->data = 66;
    fourth->next = nullptr;

    // Traverse and print the linked list
    linkedlistTraversal(head);

    // insertion at  first position
    // head=insertionAtBeginnnging(head,10);
    // linkedlistTraversal(head); // abhi jo head traversal me pass ho rha h na wo neFirstnode ko point krega

    //insertion at index
    insertAtIndex(head,101,2);  // this will not work for index 0
    linkedlistTraversal(head);

    //insertion at end
    // insertAtEnd(head,23);
    // linkedlistTraversal(head);

    //insertion after a node --> this can be acheived in  constant time complexity
    // insertAfterANode(head,third,32);
    // linkedlistTraversal(head);


   

    // Deallocate the memory (important in C++ to avoid memory leaks)
    delete head;
    delete second;
    delete third;
    delete fourth;

    // Deallocate the entire linked list
    // deleteList(head);
    // cout << "After deleting the entire list, head: " << head << endl;

    return 0;
}
