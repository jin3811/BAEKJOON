#include <bits/stdc++.h>
using namespace std;
#define MAXVALUE (int)1e7

int row;
int col = 3;
vector<vector<int>> board;

void input() {
    cin >> row;
    board.resize(row);
    for (auto& line : board) {
        line.resize(col);
        for (int& x : line) cin >> x;
    }
}

int getMaxDp() {
    int dp[row][col];
    int dx[3] = {-1, 0, 1};
    int prev;
    for (int i = 0; i < col; i++) dp[0][i] = board[0][i];
    fill(&dp[1][0], &dp[row - 1][col], 0);

    for (int i = 1; i < row; i++) { // 라인 선택
        for(int j = 0; j < col; j++) { // 해당 라인에서 원소 선택
            for (int k = 0; k < 3; k++) { // 변화량 선택
                prev = j + dx[k];
                if (prev < 0 || prev >= col) continue;

                dp[i][j] = max(dp[i][j], board[i][j] + dp[i - 1][prev]);
            }
        }
    }
    sort(dp[row - 1], dp[row - 1] + col);
    return dp[row - 1][col - 1];
}

int getMinDp() {
    int dp[row][col];
    int dx[3] = {-1, 0, 1};
    int prev;
    for (int i = 0; i < col; i++) dp[0][i] = board[0][i];
    fill(&dp[1][0], &dp[row - 1][col], MAXVALUE);

    for (int i = 1; i < row; i++) { // 라인 선택
        for(int j = 0; j < col; j++) { // 해당 라인에서 원소 선택
            for (int k = 0; k < 3; k++) { // 변화량 선택
                prev = j + dx[k];
                if (prev < 0 || prev >= col) continue;

                dp[i][j] = min(dp[i][j], board[i][j] + dp[i - 1][prev]);
            }
        }
    }
    sort(dp[row - 1], dp[row - 1] + col);
    return dp[row - 1][0];
}

void sol() {
    int maxAnswer = getMaxDp();
    int minAnswer = getMinDp();
    cout << maxAnswer << ' ' << minAnswer;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}