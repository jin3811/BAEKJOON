#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;

void input() {
    cin >> m >> n;
    graph.resize(m);
    string input;

    for(auto& row : graph) {
        cin >> input;
        for(char x : input) row.push_back(x - '0');
    }
}

// 41192KB / 36ms
bool dfs(int st_x, int st_y) {
    if (st_y == 0) return true;
    graph[st_y][st_x] = -1;

    bool result = false;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int next_x = st_x + dx[i];
        int next_y = st_y + dy[i];
        if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
        if (graph[next_y][next_x] == 0) result = result || dfs(next_x, next_y);

        if (result) return true;
    }
    return false;
}

// 6000KB / 20ms
bool bfs(int st_x) {
    queue<pair<int, int>> q;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    q.push({st_x, m - 1});
    graph[m - 1][st_x] = -1;

    while(!q.empty()) {
        auto [cur_x, cur_y] = q.front();
        q.pop();

        if (cur_y == 0) return true;

        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
            
            if (graph[next_y][next_x] == 0) {
                graph[next_y][next_x] = -1;
                q.push({next_x, next_y});
            }
        }
    }
    return false;
}

void sol() {
    for(int x = 0; x < n; x++) {
        if (graph[m - 1][x] == 0) {
            // if (bfs(x)) {
            if (dfs(x, m-1)){
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}