#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int index = 0;
    stack<int> st;
    vector<int> input;
    vector<char> ans;

    cin >> n;
    input.resize(n);
    for(int& x : input) cin >> x;

    for(int i = 1; i <= n; i++) {
        st.push(i);
        ans.push_back('+');
        while(!st.empty() && st.top() == input[index]){
            st.pop();
            ans.push_back('-');
            index++;
        }
    }

    if (!st.empty()) cout << "NO";
    else for(const auto& x : ans) cout << x << '\n';
}
