#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int test;   
    stack<string> st;
    string str;
    string token;

    cin >> test;
    cin.ignore();

    for (int i = 1; i <= test; ++i) {
        getline(cin, str);
        stringstream sstream(str);
        while(getline(sstream, token, ' ')) st.push(token);

        cout << "Case #" << i << ": ";
        while (!st.empty()) {
            token = st.top();
            st.pop();
            cout << token << ' ';
        }
       cout << '\n';
    }
}