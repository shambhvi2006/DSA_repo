#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int>& q){
    int n = q.size();
    if(n%2!=0) return; // if odd, return
    queue<int> firstHalf;
    for(int i=0;i<n/2;i++){
        firstHalf.push(q.front());
        q.pop();
    }
    while(!firstHalf.empty()){
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}
int main(){
    queue<int> q;
    int n; cout<<"Enter even number of elements: "; cin>>n;
    if(n%2!=0) return 0;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        int x; cin>>x;
        q.push(x);
    }
    interleave(q);
    cout<<"Interleaved Queue: ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}
