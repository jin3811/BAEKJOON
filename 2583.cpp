#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int m, n, k;
vector<vector<int>> graph;

void make_graph(pii& left_down , pii& right_up) {
    for (int x = left_down.first; x <= right_up.first; x++) {
        for (int y = right_up.second; y <= left_down.second; y++) {
            graph[y][x] = 1;
        }
    }
}

void input() {
    pii ld, ru; 
    cin >> m >> n >> k;
    graph.resize(m);
    for (auto& line : graph) line.resize(n, 0);
    for (int i = 0; i < k; i++) {
        cin >> ld.first >> ld.second >> ru.first >> ru.second;
        ld.second = m - 1 - ld.second;
        ru.second = m - ru.second;
        ru.first--;
        make_graph(ld, ru);
    }
}

int bfs(int x, int y) {
    queue<pii> q;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    int area = 1;
    
    q.push({x, y});
    graph[y][x] = 2;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x > -1 && next_x < n && next_y > -1 && next_y < m && graph[next_y][next_x] == 0) {
                q.push({next_x, next_y});
                graph[next_y][next_x] = 2;
                area++;
            }
        }
    }
    return area;
}

void sol() {
    vector<int> answer;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!graph[i][j]) answer.push_back(bfs(j, i));
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (const auto& x : answer) cout << x << ' ';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}