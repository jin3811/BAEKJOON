#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using pii = pair<int, int>;

int n, m;
vector<vector<int>> board;
pii goal;

void input() {
    cin >> n >> m;
    board.resize(n);

    for(int y = 0; y < n; y++) {
        board[y].resize(m);

        for(int x = 0; x < m; x++) {
            cin >> board[y][x];
            if (board[y][x] == 2) {
                goal.first = x;
                goal.second = y;
            }
        }
    }
}

void sol() {
    queue<pii> q;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int now = 0;
    pii curPos;
    bool visit[n][m] = {0}; 
    int dist[n][m] = {0};

    q.push(goal);
    dist[goal.second][goal.first] = now;

    while (!q.empty()) {
        curPos = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = curPos.first + dx[i];
            int newY = curPos.second + dy[i];
            if (newX < 0 || newX >= m ||newY < 0 || newY >= n || visit[newY][newX]) continue;
            
            dist[newY][newX] = now;
            visit[newY][newX] = true;
            q.push({newX, newY});
        }
        now++;
    }
    
    for (int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            if (dist[y][x] == 0) {
                if (board[y][x] == 0 || make_pair(x, y) == goal) { // 못가는 곳이거나 목표지점
                    continue;
                }
                else {
                    dist[y][x] == -1;
                }
            }
        }
    }

    for (int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            cout << dist[y][x] << ' ';
        }
        cout << endl;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}