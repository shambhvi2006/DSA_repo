#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList{
public:
    Node* head;
    DoublyLinkedList() : head(nullptr) {}
    void insertAtbegin(int num){
    Node* newNode = new Node(num);
    if(head == nullptr){
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode; 
}
void insertAtend(int num){
    Node* newNode = new Node(num);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertaftervalue(int num, int value){
    Node* newNode = new Node(num);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp != nullptr && temp->data != value){
        temp = temp->next;
    }
    if(temp == nullptr){
        cout << "Value not found" << endl;
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != nullptr){
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return;
}
void deleteatbegin(){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if(head != nullptr){
        head->prev = nullptr;
    }
    delete temp;
    return;
}

void deleteatend(){
    if(!head){
        cout<<"List is empty"<<endl;
    }
    else if(!head->next){
        delete head;
        head = nullptr;
    }
    else{
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
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
    while(temp != nullptr && temp->data != num){
        temp = temp->next;
    }
    if(temp == nullptr){
        cout << "Value not found" << endl;
        return;
    }
    if(temp->next != nullptr){
        temp->next->prev = temp->prev;
    }
    if(temp->prev != nullptr){
        temp->prev->next = temp->next;
    }
    delete temp;
    return;
}
void search(int num){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == num){
            cout << "Value found" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Value not found" << endl;
    return;
}
void display(){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int size() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}
};

int main() {
    DoublyLinkedList dll;
    // quick demo – edit or replace with your own tests / menu
    dll.insertAtbegin(3);
    dll.insertAtbegin(2);
    dll.insertAtend(5);
    dll.insertaftervalue(4, 3); // after 3 insert 4
    dll.display();              // 2 3 4 5

    dll.deletevalue(3);
    dll.display();              // 2 4 5

    cout << "Size of doubly linked list: " << dll.size() << endl;
    return 0;
}