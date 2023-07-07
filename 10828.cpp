#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    stack<int> st;
    string str;
    int n, temp;

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        cin >> str;

        if (str == "push") {
            cin >> temp;
            cin.ignore();
            st.push(temp);
        }
        else if (str == "pop") {
            if (!st.empty()) {
                temp = st.top();
                st.pop();
                cout << temp << '\n';
            }
            else cout << -1 << '\n';
        }
        else if (str == "size") cout << st.size() << '\n';
        
        else if (str == "empty") cout << st.empty() << '\n';

        else if (str == "top") {
            if (!st.empty()) cout << st.top() << '\n';
            else cout << -1 << '\n';
        }
    }
}