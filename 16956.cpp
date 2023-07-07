#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int r, c;
vector<string> board;

void input() {
    cin >> r >> c;
    board.resize(r);

    for(auto& x : board) {
        cin >> x;
    }
}

void solution() {
    bool flag = true;
    int nx;
    int ny;
    int dx[4] = {0, 0, -1, 1}; // 상, 하, 좌, 우
    int dy[4] = {1, -1, 0, 0};

    for(int y = 0; y < r; y++) {
        for(int x = 0; x < c; x++) {
            if(board[y][x] == 'W') {
                for(int i = 0; i < 4; i++) {
                    nx = x + dx[i];
                    ny = y + dy[i];
                    if(nx >= 0 && nx < c && ny >= 0 && ny < r) { // 그래프를 벗어나지 않는 좌표라면
                        if(board[ny][nx] == 'S') { // 양이 발견되면
                            flag = false; // 실패처리
                            goto END; // 반복문을 탈출한다.
                        }
                        else {
                            if (board[ny][nx] == '.') // 상하좌우에 늑대가 있으면 울타리를 치지 않는다.
                                board[ny][nx] = 'D'; 
                        }
                    }
                }
            }
        }
    }
END:
    cout << flag << endl;
    if(flag) {
        for(const auto& x : board) {
            cout << x << endl;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    solution();
}