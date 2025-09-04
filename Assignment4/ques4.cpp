#include <iostream>
#include <queue>
using namespace std;

void nonrepeat(string str) {
    int n = str.size();
    int count[256] = {0};  // frequency array for ASCII chars
    queue<char> q;

    for (int i = 0; i < n; i++) {
        char ch = str[i];
        count[ch]++;
        q.push(ch);

       //while hai toh jab tak repeating hai woh pop ho jayega
        while (!q.empty() && count[q.front()] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << -1 << " ";   
        else
            cout << q.front() << " ";  
    }
    cout << endl;
}

int main() {
    string str = "abcacb";
    nonrepeat(str);
    return 0;
}
