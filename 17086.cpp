#include <bits/stdc++.h>
using namespace std;
#define MAX 50

int board[MAX][MAX];
int xlen, ylen;
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void input() {
    cin >> ylen >> xlen;
    
    for(int y = 0; y < ylen; y++) {
        for(int x = 0; x < xlen; x++) {
            cin >> board[y][x];
        }
    }
}

int bfs(int x, int y) {
    bool visit[MAX][MAX] = {false, };
    queue<tuple<int, int, int>> q; // (x, y, dist)
    q.push(make_tuple(x, y, 0));
    visit[y][x] = true;

    while(!q.empty()) {
        int orix = get<0>(q.front());
        int oriy = get<1>(q.front());
        int dist = get<2>(q.front());
        q.pop();

        if (board[oriy][orix] == 1) {
            return dist;
        }

        for(int i = 0; i < 8; i++) {
            int nx = orix + dx[i];
            int ny = oriy + dy[i];
            if (nx < 0 || nx >= xlen) continue;
            if (ny < 0 || ny >= ylen) continue;
            if (visit[ny][nx]) continue;

            visit[ny][nx] = true;
            q.push(make_tuple(nx, ny, dist + 1));
        }
    }
}

void solution() {
    int max_dist = -1;

    for (int y = 0; y < ylen; y++){
        for(int x = 0; x < xlen; x++) {
            if (board[y][x] != 1) {
                max_dist = max(max_dist, bfs(x, y)); 
            }
        }
    }
    cout << max_dist;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    solution();
}