#include <bits/stdc++.h>
#define endl '\n'
#define INF 1e9
using namespace std;
using pii = pair<int, int>;

int v, e, start_node;
vector<vector<pii>> graph;

void input(){
    int st, ed, len;

    cin >> v >> e >> start_node;
    graph.resize(v + 1);

    for(int i = 0; i < e; i++) {
        cin >> st >> ed >> len;
        graph[st].push_back({len, ed});
    }
}

void sol() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    bool visit[v + 1] = {false, };
    int dist_arr[v + 1];
    fill(dist_arr, dist_arr + v + 1, INF);

    dist_arr[start_node] = 0;
    pq.push({0, start_node});

    while(!pq.empty()) {
        int prev = pq.top().second;
        pq.pop();
        if (visit[prev]) continue;        

        visit[prev] = true;
        for(const auto& elem : graph[prev]) {
            int next = elem.second, dist = elem.first;
            if (dist_arr[next] > dist_arr[prev] + dist) {
                dist_arr[next] = dist_arr[prev] + dist;
                pq.push({dist_arr[next], next});
            }
        }
    }
    
    for(int i = 1; i <= v; i++) {
        if (dist_arr[i] != INF) cout << dist_arr[i];
        else cout << "INF";
        cout << endl;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    sol();
}