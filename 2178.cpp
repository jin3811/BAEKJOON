#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> maze;

void input() {
    cin >> n >> m;
    maze.resize(n);
    for(auto& x : maze) cin >> x;
}

void sol() { // bfs
    queue<tuple<int, int, int>> q;
    int dx[4] = {1, 0, -1, 0}; // 동 남 서 북
    int dy[4] = {0, 1, 0, -1};
    
    q.push({0, 0, 1}); // {y, x, dist}
    maze[0][0] = '2';

    while(!q.empty()) {
        int curr_y = get<0>(q.front());
        int curr_x = get<1>(q.front());
        int dist = get<2>(q.front());
        q.pop();

        if (curr_x == m - 1 && curr_y == n - 1) {
            cout << dist;
            break;
        }
        // maze[curr_y][curr_x] = '2'; // visited << 메모리 초과
        for(int i = 0; i < 4; i++) {
            int next_x = curr_x + dx[i];
            int next_y = curr_y + dy[i];
            if(next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) continue;

            if(maze[next_y][next_x] == '1') {
                q.push({next_y, next_x, dist + 1});
                maze[next_y][next_x] = '2'; // visited << 성공
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}