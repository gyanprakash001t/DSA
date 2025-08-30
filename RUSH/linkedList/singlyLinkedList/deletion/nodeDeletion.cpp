#include <iostream> // For standard I/O
using namespace std;

struct Node
{
    int data;
    Node *next; // Pointer to the next node
};

void linkedlistTraversal(Node *ptr)
{

    while (ptr != nullptr)
    { // nullptr is the C++ equivalent of NULL
        cout << "Element is: " << ptr->data << endl;
        ptr = ptr->next; // Move to the next node
    }
}

Node *deleteHeadNode(Node *head)
{

    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *deleteAtIndex(Node *head, int index){
    Node *temp = head;
    for (int i = 0; i < index-1 ; i++) {
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
    return head;
}
Node* deleteTailNode(Node* head){
    Node*temp=head;
    while(temp->next->next !=nullptr){
        temp=temp->next;
    }
    Node*temp2= temp->next;
    temp->next=nullptr;
    delete temp2;
    return head;


}
// deltion if a pointer to a node is given
Node* deleteAfterAGivenNode(Node*head,Node*node){
    Node* deletingNode = node->next;
    node->next = deletingNode->next;
    delete deletingNode;
    return head;
}

// Function to delete the entire linked list to free the heap memory
// void deleteList(Node *head)
// {
//     Node *temp;
//     while (head != nullptr)
//     {
//         temp = head;
//         head = head->next;
//         delete temp;
//     }
// }

int main()
{
    // Pointers to nodes
    Node *head;
    Node *second;
    Node *third;
    Node *fourth;

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
    cout << "elements before deletion \n";
    linkedlistTraversal(head);

    // Deletion at head
    // head = deleteHeadNode(head);
    // cout << "elements after deletion \n";
    // linkedlistTraversal(head);

    // deletion of a node at a given index
    // head= deleteAtIndex(head,1);
    // cout << "elements after deletion \n";
    // linkedlistTraversal(head);

    //deletion at tail
    // head= deleteTailNode(head);
    // cout << "elements after deletion \n";
    // linkedlistTraversal(head);
    
    //deletion after a node
    head= deleteAfterAGivenNode(head,second);
    cout << "elements after deletion \n";
    linkedlistTraversal(head);
    

    // Deallocate the memory (important in C++ to avoid memory leaks)
    delete head;
    delete second;
    delete third;
    delete fourth;

    // Deallocate the entire linked list
    // deleteList(head);

    return 0;
}
