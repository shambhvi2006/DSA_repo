#include <iostream>
#include <stack>
using namespace std;
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0; 
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string infixToPrefix(string infix) {
    stack<char> s;
    string reverse = "";
    for(int i = infix.length()-1; i >= 0; i--) {
        if(infix[i] == '(') {
            reverse += ')';
        }
        else if(infix[i] == ')') {
            reverse += '(';
        }
        else {
            reverse += infix[i];
        }
    }
    infix = reverse;
    string prefix = "";

    for(char c : infix) {
        //agar character hai toh sidha prefix mein daal do
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            prefix += c;
        }
        //opening bracket
        else if(c == '(') {
            s.push(c);
        }
        //closing bracket mei top ko dalte raho tab tak daalo jab tak 
        // opening bracket na mil jaye and then opening bracket nikal lo

        else if(c == ')') {
            while(!s.empty() && s.top() != '(') {
                prefix += s.top();
                s.pop();
            }
            s.pop(); 
        }
        //operator daalo jab tak top wale ki precedence is less than current operator ki precedence
        else if(isOperator(c)) {
            while(!s.empty() && precedence(s.top()) > precedence(c)) {//##### no equal to =
                prefix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while(!s.empty()) {
        prefix += s.top();
        s.pop();
    }

    return prefix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    string prefix = infixToPrefix(infix);
    int i = 0, j = prefix.length() - 1;
    while (i < j) {
        swap(prefix[i], prefix[j]);
        i++;
        j--;
    }
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
