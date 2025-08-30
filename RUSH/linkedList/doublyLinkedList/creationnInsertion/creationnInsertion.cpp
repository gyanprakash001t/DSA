#include <iostream>
using namespace std;

// Define a node of the doubly linked list
struct Node {
    int data;
    Node* prev;  // Pointer to the previous node
    Node* next;  // Pointer to the next node
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    
    if (head == nullptr) {
        // If the list is empty, the new node becomes the head
        return newNode;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    
    return head;
}

// Function to traverse the doubly linked list in forward direction
void traverseForward(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    cout << "Traversing in forward direction: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to traverse the doubly linked list in reverse direction
void traverseBackward(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    // Move to the last node
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    cout << "Traversing in backward direction: ";
    // Now traverse backwards using the prev pointer
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Function to delete the entire doubly linked list
void deleteList(Node* &head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    // Insert nodes into the doubly linked list
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    // Traverse the doubly linked list in forward direction
    traverseForward(head);

    // Traverse the doubly linked list in backward direction
    traverseBackward(head);

    // Free memory by deleting the entire list
    deleteList(head);

    // Check if the list is successfully deleted
    cout << "After deletion: ";
    traverseForward(head);

    return 0;
}
