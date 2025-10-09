#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string posttoin(string str){
    int n = str.length();
    stack<string> st;

    for (int i = 0; i < n; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || 
            (str[i] >= 'A' && str[i] <= 'Z') || 
            (str[i] >= '0' && str[i] <= '9')) {
            st.push(string(1, str[i]));   // push operand
        }
        else if (isOperator(str[i])) {
            // pop two operands
            string right = st.top(); st.pop();
            string left  = st.top(); st.pop();

            // build fresh result for this operator
            string expr = "(" + left + str[i] + right + ")";
            st.push(expr);
        }
    }

    // final answer is the only element left
    return st.top();
}

int main() {
    string post = "abc-+de-fg-h+/*";
    cout << "Infix: " << posttoin(post) << endl;
    return 0;
}

