#include <bits/stdc++.h>
using namespace std;

int row, col;
int ans = -1;
vector<vector<int>> graph;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void input() { // wall 1, wall 2, wall 3
    int temp;
    cin >> row >> col;
    graph.resize(row);
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> temp;
            graph[i].push_back(temp);
        }
    }
}

int bfs() {
    vector<vector<int>> copy_graph;
    queue<pair<int, int>> q;
    int x, y;
    int next_x, next_y;
    copy_graph.assign(graph.begin(), graph.end());

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(copy_graph[i][j] == 2) q.push({i, j});
        }
    }

    while(!q.empty()) {
        x = q.front().second;
        y = q.front().first;
        q.pop();

        for (int i = 0; i < 4; i++) {
            next_x = x + dx[i];
            next_y = y + dy[i];
            if (next_x > -1 && next_x < col && next_y > -1 && next_y < row && copy_graph[next_y][next_x] == 0) {
                q.push({next_x, next_y});
                copy_graph[next_y][next_x] = 2;
            }
        }
    }
    int cnt = 0;
    for(auto& row : copy_graph) {
        for(int& x : row) {
            if (x == 0) cnt++;
        }
    }
    return cnt;
}

void printV() {
    for(const auto& row : graph) {
        for(const auto& x : row) {
            cout << x << ' ';
        }
        cout << endl;
    }

}

void make_wall(int cnt) {
    if(cnt == 3) {
        printV(); 
        int temp = bfs();
        ans = max(ans, temp);
        cout << temp << "\n\n";
        return;
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(graph[i][j] == 0) {
                graph[i][j] = 1;
                make_wall(cnt + 1);
                graph[i][j] = 0;
            }
        }
    }
}

void sol() {
    make_wall(0);
    cout << ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}