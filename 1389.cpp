#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> graph;

void input() {
    int m, h1, h2;
    cin >> n >> m;

    graph.resize(n + 1);

    for(int i = 0; i < m; i++) {
        cin >> h1 >> h2;
        graph[h1].push_back(h2);
        graph[h2].push_back(h1);
    }
}

int bfs(int start) {
    int dist_arr[n + 1] = {0, };
    bool visit[n + 1] = {false, };
    queue<pair<int, int>> q;

    q.push({start, 0});
    visit[start] = true;

    while(!q.empty()) {
        int prev = q.front().first;
        int prev_dist = q.front().second;
        q.pop();
        
        for(auto& next : graph[prev]) {
            if (!visit[next]) {
                q.push({next, prev_dist + 1});
                visit[next] = true;
                dist_arr[next] = prev_dist + 1;
            }
        }
    }
    return accumulate(dist_arr + 1, dist_arr + n + 1, 0);
}

void sol() {
    int result = 0;
    int kbnum = INT32_MAX;
    int temp;
    for(int i = 1; i <= n; i++) {
        temp = bfs(i);
        if (kbnum > temp) {
            kbnum = temp;
            result = i;
        }
    }
    cout << result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    sol();
}