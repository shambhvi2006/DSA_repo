#include <iostream>
using namespace std;
#include <queue>

class stack{
    queue<int> q1;
    public:
    void push(int x){
        q1.push(x);
        int sz=q1.size();
        for(int i=0;i<sz-1;i++){
            q1.push(q1.front());
            q1.pop();
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