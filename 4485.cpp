#include <bits/stdc++.h>
#define endl '\n'
#define INF (int)1e9
using namespace std;
using tii = tuple<int, int, int>; // 순서대로 거리, x, y

int n;
vector<vector<int>> graph;

void input() {
    graph.clear();
    graph.resize(n);
    for(auto& row : graph) {
        row.resize(n);
        for(auto& x : row) cin >> x;
    }
}

int sol() {
    priority_queue<tii, vector<tii>, greater<tii>> pq;
    int dx[4] = {1, 0, -1, 0}; // 동, 남, 서, 북
    int dy[4] = {0, 1, 0, -1};
    vector<vector<int>> dist(n, vector<int>(n, INF));
    
    dist[0][0] = graph[0][0];
    pq.push({dist[0][0], 0, 0});

    while(!pq.empty()) {
        auto[cur_dist, cur_x, cur_y] = pq.top();
        pq.pop();

        if (cur_dist > dist[cur_y][cur_x]) continue;

        for(int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n) continue;

            int next_dist = cur_dist + graph[next_y][next_x];
            if(dist[next_y][next_x] > next_dist) {
                dist[next_y][next_x] = next_dist;
                pq.push({next_dist, next_x, next_y});
            }

        }
    }
    return dist[n - 1][n - 1];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 1; ; i++) {
        cin >> n;
        if(!n) break;
        input();
        cout << "Problem " << i << ": " << sol() << endl;
    }
}