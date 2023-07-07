#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;
using pii = pair<int, int>;

int n, m, x;
vector<vector<pii>> stod_graph, dtos_graph; // start to destination, destination to start
vector<int> stod_dist, dtos_dist;


void input() {
    int from, to, dist;
    cin >> n >> m >> x;
    stod_graph.resize(n + 1);
    dtos_graph.resize(n + 1);
    stod_dist.resize(n + 1, INF);
    dtos_dist.resize(n + 1, INF);
    for(int i = 0; i < m; i++) {
        cin >> from >> to >> dist;
        stod_graph[from].push_back({dist, to});
        dtos_graph[to].push_back({dist, from});
    }
}

void dijkstra(vector<vector<pii>>& graph, vector<int>& dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, x});
    dist[x] = 0;
    
    while(!pq.empty()) {
        auto[cur_dist, cur_pos] = pq.top();
        pq.pop();

        if (cur_dist > dist[cur_pos]) continue;

        for (auto& elem : graph[cur_pos]) {
            auto[nx_dist, nx_pos] = pq.top();
            nx_dist += cur_dist;
            if (nx_dist < dist[nx_pos]) {
                dist[nx_pos] = nx_dist;
                pq.push({nx_dist, nx_pos});
            }
        }
    }
}

void sol() {
    int max_dist = -1;
    dijkstra(stod_graph, stod_dist);
    dijkstra(dtos_graph, dtos_dist);
    
    for(int i = 1; i <= n; i++) max_dist = max(max_dist, stod_dist[i] + dtos_dist[i]);
    cout << max_dist;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}