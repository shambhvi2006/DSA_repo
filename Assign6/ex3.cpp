// C++ code to reverse a doubly linked 
// list in groups of K size

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

// Helper function to reverse K nodes
Node *reverseKNodes(Node *head, int k) {
    Node *curr = head, *prev = nullptr, *next = nullptr;
    int count = 0;

    while (curr != nullptr && count < k) {
        next = curr->next;
        curr->next = prev;
        curr->prev = nullptr;
        if (prev != nullptr) {
            prev->prev = curr;
        }
        prev = curr;
        curr = next;
        count++;
    }

    return prev;
}

// Recursive function to reverse in groups of K
Node *reverseKGroup(Node *head, int k) {
    if (head == nullptr) {
        return head;
    }
    Node *groupHead = nullptr;
    Node *newHead = nullptr;

    // Move temp to the next group
    Node *temp = head;
    int count = 0;
    while (temp && count < k) {
        temp = temp->next;
        count++;
    }

    // Reverse the first K nodes
    groupHead = reverseKNodes(head, k);

    // Connect the reversed group with the next part
    if (newHead == nullptr) {
        newHead = groupHead;
    }

    // Recursion for the next group
    head->next = reverseKGroup(temp, k);
    if (head->next != nullptr) {
        head->next->prev = head;
    }

    return newHead;
}

void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
  
    // Creating a sample doubly linked list:
    // 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    head = reverseKGroup(head, 2);
    printList(head);

    return 0;
}