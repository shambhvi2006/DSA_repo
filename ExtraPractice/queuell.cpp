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

// Queue class
class Queue {
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue (insert element at rear)
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (rear == nullptr) {
            front = rear = newNode;
            cout << value << " enqueued to queue\n";
            return;
        }
        rear->next = newNode;
        rear = newNode;
        cout << value << " enqueued to queue\n";
    }

    // Dequeue (remove element from front)
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front;
        cout << front->data << " dequeued from queue\n";
        front = front->next;

        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    // Peek front element
    void peek() {
        if (front == nullptr) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Front element: " << front->data << endl;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.peek();
    q.dequeue();
    q.peek();

    return 0;
}
