#include <iostream>  // For standard I/O
 using namespace std;

struct Node {
    int data;
    Node* next;  // Pointer to the next node
};

void linkedlistTraversal(Node* ptr) {
    while (ptr != nullptr) {  // nullptr is the C++ equivalent of NULL
        cout << "Element is: " << ptr->data << endl;
        ptr = ptr->next;  // Move to the next node
    }
}


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
    
    // Deallocate the memory (important in C++ to avoid memory leaks)
    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}
