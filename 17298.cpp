#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, input, elem, nge;
    stack<int> st;
    stack<int> temp;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> input;
        st.push(input);
    }

    for(int i = 1; i < n; i++) {
        nge = -1;
        while(st.size() > i) {
            temp.push(st.top());
            st.pop();
        }
        elem = st.top();
        while(!temp.empty()) {
            if(nge == -1 && elem < temp.top())
                nge = temp.top();
            st.push(temp.top());
            temp.pop();
        }
        cout << nge << ' ';
    }
    cout << -1;
}
