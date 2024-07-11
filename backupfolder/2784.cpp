#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

string words[6], board[3];
map<string, bool> checklist;
bool valid;
string answer="ZZZZZZZZZ";

void input() {
    for (int i = 0; i < 6; i++) {
        cin >> words[i];
        checklist[words[i]] = true;
    }
    for (int i = 0; i < 6; i++) {
        board[i].resize(3, '-');
    }
}

bool isValid() {
    string newStr;
    for(int i = 0; i < 3; i++) {
        if (!checklist[board[i]]) return false;

        newStr.resize(0);
        for (int j = 0 ; j < 3; j++) newStr += board[i][j];
        if (!checklist[newStr]) return false;
    }
    return true;
}

void bactracking(int cnt, int cur) {
    if (!cnt) {
        if (isValid()) {
            valid = true;
            answer = min(answer, board[0] + board[1] + board[2]);
        }
    }

    bool isChanged[3] = {false};
    // 가로 배치
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == '-' || board[i][0] == words[cur][0])
    }

    // 세로 배치
    for (int i = 0; i < 3; i++) {

    }
}

void sol() {
    bactracking(9, 0);
    cout << (valid ? answer : 0);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    input();
    sol();
}