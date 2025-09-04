#include <iostream>
using namespace std;

#define MAX 1000

int a[MAX];
int frontIdx = 0, rearIdx = -1, cap = 0;

bool isEmpty() { 
    return (frontIdx > rearIdx); 
}
bool isFull()  { 
    return rearIdx == cap - 1; 
}

void enqueue(int x){
    if(isFull()) cout << "Queue full\n";
    else {
        ++rearIdx;
        a[rearIdx] = x;
    }
}

void dequeue(){
    if(isEmpty()) cout << "Queue empty\n";
    else ++frontIdx;
}

void peek(){
    if(isEmpty()) cout << "Queue empty\n";
    else cout << a[frontIdx] << "\n";
}

void display(){
    if(isEmpty()){ cout << "Queue empty\n"; return; }
    for(int i = frontIdx; i <= rearIdx; ++i) {
        cout << a[i] << ' ';
    }
    cout << "\n";
}

int main(){
    cout << "Capacity (<= " << MAX << ")? ";
    if(!(cin >> cap) || cap <= 0 || cap > MAX) return 0;

    while(true){
        cout << "\n1.Enq 2.Deq 3.isEmpty 4.isFull 5.Display 6.Peek 0.Exit : ";
        int ch; if(!(cin >> ch)) break;
        if(ch==0) break;
        if(ch==1){ int x; cin >> x; enqueue(x); }
        else if(ch==2) dequeue();
        else if(ch==3) cout << (isEmpty()?"true\n":"false\n");
        else if(ch==4) cout << (isFull() ?"true\n":"false\n");
        else if(ch==5) display();
        else if(ch==6) peek();
    }
    return 0;
}
