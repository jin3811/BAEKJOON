#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool is_vps(string& str) {
    if (str[0] == ')' || str[str.length() - 1] == '(')
        return false;
    
    else {
        stack<char> st;
        
        for(const auto& x : str) {
            if(x == '(') st.push(x);
            else {
                if (st.empty()) return false;
                else st.pop();
            }
        }
        return st.empty();
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    bool flag;
    string str;
    stack<char> st;

    cin >> t;
    
    while(t--) {
        cin >> str;
        if(is_vps(str)) cout << "YES\n";
        else cout << "NO\n";
    }
}