#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string change_to_ps(string& str){
    string result = "";
    for(char& x : str) {
        if(!isalpha(x) && !isblank(x) && x != '.') result += x;
    }
    return result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string line;
    while(true) {
        stack<char> st;
        getline(cin, line);
        if (line == ".") break;

        line = change_to_ps(line);
        // ")string(" 이나 "]string["같은 문자열인지 사전에 미리 검사
        if(*line.begin() == ')' || *line.begin() == ']' || *(line.end() - 1) == '(' || *(line.end() - 1) == '['){
            cout << "no" << endl;
            continue;
        }
        else {
            for(const char& x : line) {
                if (x == '(' || x == '[') st.push(x);
                else if(x == ')'){
                    if (!st.empty() && st.top() == '(') st.pop();
                    else st.push(x);
                }
                else if(x == ']'){
                    if (!st.empty() && st.top() == '[') st.pop();
                    else st.push(x);
                }
            }
        }

        if (st.empty()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}