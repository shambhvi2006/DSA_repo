#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
    friend class LinkedList;
};
class LinkedList {
private:
    Node* head; 
public:
    LinkedList(){
        head = nullptr;
    }
    void insertAtStart(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }
    void insertAtEnd(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = n;
    }
    void insertinbetween(int val, int pos) {
        if (pos == 0) {
            insertAtStart(val);
            return;
        }
        Node* n = new Node(val);
        Node* cur = head;
        for (int i = 0; i < pos - 1 && cur; i++) {
            cur = cur->next;
        }
        if (!cur) {
            cout << "Position out of bounds\n";
            delete n;
            return;
        }
        n->next = cur->next;
        cur->next = n;
    }
    void deleteAtStart() {
        if (!head) return;
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    void deleteAtEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* cur = head;
        while (cur->next && cur->next->next) {
            cur = cur->next;
        }
        delete cur->next;
        cur->next = nullptr;
    }
    void deleteinbetween(int pos) {
        if (pos == 0) {
            deleteAtStart();
            return;
        }
        Node* cur = head;
        for (int i = 0; i < pos - 1 && cur; i++) {
            cur = cur->next;
        }
        if (!cur || !cur->next) {
            cout << "Position out of bounds\n";
            return;
        }
        Node* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
    }
    void search(int val) {
        Node* cur = head;
        int pos = 0;
        while (cur) {
            if (cur->data == val) {
                cout << "Value " << val << " found at position " << pos << "\n";
                return;
            }
            cur = cur->next;
            pos++;
        }
        cout << "Value " << val << " not found in the list\n";
    }
    void display() {
        if (!head) {
            cout << "Empty List\n";
            return;
        }
        Node* cur = head;
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << "->";
            cur = cur->next;
        }
        cout << "\n";
    }
    void deleteoccurences(int val) {
        while (head && head->data == val) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
        Node* cur = head;
        while (cur && cur->next) {
            if (cur->next->data == val) {
                Node* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
    }
    Node* findingmidpoint(){
        Node* fast=head, *slow=head;
        while(fast!=nullptr && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
};

int main() {
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtStart(5);
    list.insertinbetween(15, 2);
    list.insertAtEnd(15);
    list.insertAtEnd(15);
    list.insertinbetween(15, 0);
    list.display(); // 15->5->10->15->20->15->15
    list.deleteoccurences(15);
    list.display(); // 5->10->20
    Node* mid=list.findingmidpoint();
    if(mid) cout<<"Midpoint is: "<<mid->data<<"\n"; // Mid
    return 0;
}
