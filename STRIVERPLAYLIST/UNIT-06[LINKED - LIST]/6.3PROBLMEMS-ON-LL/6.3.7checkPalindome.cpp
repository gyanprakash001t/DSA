#include<bits/stdc++.h>
using namespace std;

// using tortoise and hare find out the middle element and  in case of even your slow should point m1(first) and in case of odd slow  should point middle
// then we'll reverse the second part 
// comapre the first and seond part;

class Node 
{
   public:
  
    int data;   
    Node* next;      
    Node(int data1, Node* next1) 
    {
        data = data1;
        next = next1;
    }

    Node(int data1) 
    {
        data = data1;
        next = nullptr;
    }
};

// Function to reverse a linked list

Node* reverseLinkedList(Node* head) {
   
    if (head == NULL || head->next == NULL) 
    {
        return head; 
    }

    Node* newHead = reverseLinkedList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

bool isPalindrome(Node* head) {
    
    if (head == NULL || head->next == NULL) 
    {
        return true; 
    }
    
    Node* slow = head;
    Node* fast = head;
    
    
    while (fast->next != NULL && fast->next->next != NULL) 
    {
    
        slow = slow->next;  
        fast = fast->next->next;  
    }
    
    // Reverse the second half of the
    Node* newHead = reverseLinkedList(slow->next);

    Node* first = head;  
    Node* second = newHead; 
    
    while (second != NULL) {
        
        // Compare data values of 
        // nodes from both halves
        
        // If values do not match,
        // the list is not a palindrome
        if (first->data != second->data) {
            
            // Reverse the second half 
            // back to its original state
            reverseLinkedList(newHead);  
            
            // Not a palindrome
            return false;
        }
        
         // Move the first pointer
        first = first->next; 
        
        // Move the second pointer
        second = second->next;  
    }
    
    // Reverse the second half
    // back to its original state
    reverseLinkedList(newHead);  
    
    // The linked list is a palindrome
    return true;  
}



// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with
    // values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}