#include <bits/stdc++.h>
using namespace std;

int n;
int* num_elem;
string infix;

void input() {
    cin >> n;
    cin >> infix;
    num_elem = new int[n];

    for(int i = 0; i < n; i++) cin >> num_elem[i];
}

void solution() {
    stack<double> compute_infix;
    double n1, n2;
    for(const auto& x : infix) {
        if(x >= 'A' && x <= 'Z') compute_infix.push(num_elem[x - 'A']);
        else {
            n2 = compute_infix.top();
            compute_infix.pop();
            n1 = compute_infix.top();
            compute_infix.pop();

            switch(x) {
            case '+':
                compute_infix.push(n1 + n2);
                break;
            case '-':
                compute_infix.push(n1 - n2);
                break;
            case '*':
                compute_infix.push(n1 * n2);
                break;
            case '/':
                compute_infix.push(n1 / n2);
                break;
            }
        }
    }
    cout << compute_infix.top();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;
    cout.precision(2);

    input();
    solution();
}