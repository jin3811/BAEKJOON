#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    queue<int> q;
    string str;
    int n, temp;

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        cin >> str;

        if (str == "push") {
            cin >> temp;
            cin.ignore();
            q.push(temp);
        }
        else if (str == "pop") {
            if (!q.empty()) {
                temp = q.front();
                q.pop();
                cout << temp << '\n';
            }
            else cout << -1 << '\n';
        }
        else if (str == "size") cout << q.size() << '\n';
        
        else if (str == "empty") cout << q.empty() << '\n';

        else if (str == "front") {
            if (!q.empty()) cout << q.front() << '\n';
            else cout << -1 << '\n';
        }
        else if (str == "back") {
            if (!q.empty()) cout << q.back() << '\n';
            else cout << -1 << '\n';
        }
    }
}