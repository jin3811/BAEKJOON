#include <bits/stdc++.h>
using namespace std;

bool solution(deque<int>& dq, string& command){
    bool rev = false;
    for(char& cmd : command) {
        if (cmd == 'R') rev = !rev;
        else {
            if (dq.size() == 0) return false;

            if (rev) dq.pop_back();
            else dq.pop_front();
        }
    }
    if (rev) reverse(dq.begin(), dq.end());
    return true;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    deque<int> dq;
    string command, line, token;
    int tcase, cnt;

    cin >> tcase;
    while(tcase--) {
        cin >> command >> cnt >> line;
        
        rotate(line.begin(), line.begin() + 1, line.end());
        line.pop_back(); line.pop_back();
        stringstream sstream(line);
        while(getline(sstream, token, ',')) dq.push_back(stoi(token));

        if(solution(dq, command)) {
            cout << '[';
            while(!dq.empty()) {
                cout << dq.front();
                dq.pop_front();
                if (dq.size() >= 1) cout << ',';
            }
            cout << "]\n";
        } 
        else cout << "error\n";
    }
}