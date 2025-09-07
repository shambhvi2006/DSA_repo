#include <iostream>
#include <queue>

using namespace std;

void printBinary1toN(int n) {
    if (n <= 0) return;
    queue<string> q;
    q.push("1");

    for (int i = 0; i < n; ++i) {
        string s = q.front(); 
        q.pop();
        cout << s << ' '; 
        q.push(s + "0");
        q.push(s + "1");
    }
}

int main() {
    int n = 10;      // example
    printBinary1toN(n); // Output: 1 10
    return 0;
}
