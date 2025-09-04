#include <iostream>
using namespace std;

#define SIZE 5  // size of circular queue

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot enqueue " << value << endl;
            return;
        }

        if (front == -1) front = 0;  // first insertion
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        cout << value << " enqueued successfully." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Cannot dequeue." << endl;
            return;
        }

        int removed = arr[front];
        if (front == rear) {
            // only one element left
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }

        cout << removed << " dequeued successfully." << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Nothing to peek." << endl;
        } else {
            cout << "Front element = " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return;
        }

        cout << "Circular Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

// Main menu-driven program
int main() {
    CircularQueue cq;
    int choice, value;

    do {
        cout << "\n--- Circular Queue Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek (Front Element)" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Display Queue" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;

            case 2:
                cq.dequeue();
                break;

            case 3:
                cq.peek();
                break;

            case 4:
                cout << (cq.isEmpty() ? "Queue is EMPTY." : "Queue is NOT empty.") << endl;
                break;

            case 5:
                cout << (cq.isFull() ? "Queue is FULL." : "Queue is NOT full.") << endl;
                break;

            case 6:
                cq.display();
                break;

            case 0:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}

