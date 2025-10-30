#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr){}
};

class CircularLinkedList{
public:
    Node* head;
    CircularLinkedList() : head(nullptr) {}
    void insertAtbegin(int num){
    Node* newNode = new Node(num);
    if(head == nullptr){
        head = newNode;
        newNode->next = head; // point to itself
        return;
    }
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}
void insertAtend(int num){
    Node* newNode = new Node(num);
    if(head == nullptr){
        head = newNode;
        newNode->next = head; // point to itself
        return;
    }
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}
void insertaftervalue(int num, int value){
    Node* newNode = new Node(num);
    if(head == nullptr){
        head = newNode;
        newNode->next = head; // point to itself
        return;
    }
    Node* temp = head;
    while(temp->data != value){
        temp = temp->next;
        if(temp == head){ // completed a full circle
            cout << "Value not found" << endl;
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return;
}
void deleteatbegin(){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    if(head->next == head){ // only one node
        head = nullptr;
        delete temp;
        return;
    }
    Node* curr = head;
    while(curr->next != head){
        curr = curr->next;
    }
    curr->next = head->next;
    head = head->next;
    delete temp;
    return;
}
void deleteatend(){
    if(!head){
        cout<<"List is empty"<<endl;
    }
    else if(head->next == head){ // only one node
        delete head;
        head = nullptr;
    }
    else{
        Node* temp = head;
        while(temp->next->next != head){
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = head;
        delete toDelete;
    }
}
void deletevalue(int num){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }
    if(head->data == num){
        deleteatbegin();
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    do{
        prev = temp;
        temp = temp->next;
        if(temp->data == num){
            prev->next = temp->next;
            delete temp;
            return;
        }
    } while(temp != head);
    cout << "Value not found" << endl;
    return;
}
void search(int num){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    do{
        if(temp->data == num){
            cout << "Value found" << endl;
            return;
        }
        temp = temp->next;
    } while(temp != head);
    cout << "Value not found" << endl;
    return;
}
void display(){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);
    cout<<head->data<<" (head again)"; // to show circular nature
    cout << endl;
}
void sizeCircular() {
    if (head == nullptr)
        return;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    cout << "Size of circular linked list: " << count << endl;
}
void ifcircular(){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head->next;
    while(temp != nullptr && temp != head){
        temp = temp->next;
    }
    if(temp == head){
        cout << "List is circular" << endl;
    } else {
        cout << "List is not circular" << endl;
    }
}
};

int main(){
    CircularLinkedList dll;
    dll.insertAtend(5);
    dll.insertAtend(4);
    dll.insertAtend(3);
    dll.display();
    
    dll.sizeCircular();
    dll.ifcircular();
    return 0;
}