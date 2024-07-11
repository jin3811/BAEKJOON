#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n;
string query;
bool board[2001][2001];

void input() {
    cin >> n;
    cin.ignore();
    cin >> query;
}

void sol() {
    int x = 1000, y = 1000, answer = 0;
    board[y][x] = true;
    for (char q : query) {
        if (q == 'N') y--;
        else if (q == 'S') y++;
        else if (q == 'E') x++;
        else x--;

        board[y][x] = true;
    }

    for (int i = 0; i < 2001; i++) {
        for (int j = 0; j < 2001; j++) {
            if (board[i][j]) answer++;
        }
    }

    cout << answer;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    input();
    sol();
}