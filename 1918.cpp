#include <bits/stdc++.h>
using namespace std;

int prec(char op) { // 연산자 우선순위
    if (op == ')' || op == '(') return 0;
    else if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/') return 2;
    return -1;
}

void solution(string& infix) {
    string postfix = "";
    stack<char> op_stack;
    for(const char& elem : infix) {
        if (elem == '+' || elem == '-' || elem == '*' || elem == '/') {
            while(!op_stack.empty() && prec(elem) <= prec(op_stack.top())) {
                postfix += op_stack.top();
                op_stack.pop();
            }
            op_stack.push(elem);
        }
        else if (elem == '(') {
            op_stack.push(elem);
        }
        else if (elem == ')') {
            while(op_stack.top() != '(') {
                postfix += op_stack.top();
                op_stack.pop();
            }
            op_stack.pop();
        }
        else {
            postfix += elem;
        }
    }
    while (!op_stack.empty()) {
        postfix += op_stack.top();
        op_stack.pop();
    }
    cout << postfix;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string infix;
    cin >> infix;
    solution(infix);
}