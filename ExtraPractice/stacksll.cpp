#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Stack class
class Stack {
    Node* top;
public:
    Stack() { 
        top = nullptr; 
    }

    // Push element onto stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to stack\n";
    }

    // Pop element from stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        cout << top->data << " popped from stack\n";
        top = top->next;
        delete temp;
    }

    // Peek top element
    void peek() {
        if (top == nullptr) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Top element: " << top->data << endl;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.peek();
    s.pop();
    s.peek();

    return 0;
}
