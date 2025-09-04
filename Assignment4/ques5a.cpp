#include <iostream>
using namespace std;
#include <queue>

class stack{
    queue<int> q1,q2;
    public:
    void push(int x){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop(){
        int x = q1.front();
        q1.pop();
    }
    int top(){
        return q1.front();
    }   
    bool empty(){
        return q1.empty();
    }
     
};
int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top()<<endl; //3
    s.pop();
    cout<<s.top()<<endl; //2
    s.pop();
    cout<<s.top()<<endl; //1
    s.pop();
    cout<<s.empty()<<endl; //1 (true)
    return 0;
}
