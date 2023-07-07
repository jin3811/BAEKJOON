#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    deque<int> dq;
    string str;
    int n, temp;

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        cin >> str;

        if (str == "push_back") {
            cin >> temp;
            cin.ignore();
            dq.push_back(temp);
        }
        else if (str == "push_front") {
            cin >> temp;
            cin.ignore();
            dq.push_front(temp);
        }
        else if (str == "pop_back") {
            if (!dq.empty()) {
                temp = dq.back();
                dq.pop_back();
                cout << temp << '\n';
            }
            else cout << -1 << '\n';
        }
        else if (str == "pop_front") {
            if (!dq.empty()) {
                temp = dq.front();
                dq.pop_front();
                cout << temp << '\n';
            }
            else cout << -1 << '\n';
        }
        else if (str == "size") cout << dq.size() << '\n';
        
        else if (str == "empty") cout << dq.empty() << '\n';

        else if (str == "front") {
            if (!dq.empty()) cout << dq.front() << '\n';
            else cout << -1 << '\n';
        }
        else if (str == "back") {
            if (!dq.empty()) cout << dq.back() << '\n';
            else cout << -1 << '\n';
        }
    }
}