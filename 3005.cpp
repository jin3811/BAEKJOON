#include <bits/stdc++.h>
#define ALPHACNT 26
using namespace std;

int r, c;
bool alphaInBoard[ALPHACNT] = { false };
vector<string> board;

void input() {
    cin >> r >> c;
    board.resize(r);
    for (auto& line : board) {
        cin >> line;
        for (char alpha : line) {
            if (alpha != '#') alphaInBoard[alpha - 'a'] = true;
        }
    }
}

string getRowWord(int x, int y) {
    string word;
    word += board[y][x];
    if (x > 0 && board[y][x - 1] != '#') return word;

    for(int col = x + 1; col < c; col++) {
        if (board[y][col] == '#') break;
        word += board[y][col];
    }
    return word;
}

string getColWord(int x, int y) {
    string word;
    word += board[y][x];
    if (y > 0 && board[y - 1][x] != '#') return word;
        
    for(int row = y + 1; row < r; row++) {
        if (board[row][x] == '#') break;
        word += board[row][x];
    }
    return word;
}

string& compareTwoSubStr(string& row, string& col) {
    if (row.length() == 1) return col;
    else if (col.length() == 1) return row;
    else return row < col ? row : col;
}

void sol() {
    string answer = "zzzzzzzzzzzzzzzzzzzzz";
    string row;
    string col;

    for (int i = 0; i < ALPHACNT; i++) {
        // 등장하지 않는 알파벳이면 검사하지 않는다.
        if (!alphaInBoard[i]) continue;

        for(int y = 0; y < r; y++) {
            for(int x = 0; x < c; x++) {
                if (board[y][x] == i + 'a') {
                    row = getRowWord(x, y);
                    col = getColWord(x, y);
                    if (row.length() == 1 && col.length() == 1) continue;
                    
                    string& shorterStr = compareTwoSubStr(row, col);
                    answer = answer < shorterStr ? answer : shorterStr;
                }
            }
        }
    }

    cout << answer;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}