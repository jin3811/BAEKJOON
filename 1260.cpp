#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m, v;
vector<vector<int>> graph;
bool* visited;

void input() {
    int from, to;

    cin >> n >> m >> v;
    graph.resize(n + 1);
    visited = new bool[n + 1];

    for(int i = 0; i < m; i++) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for(int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
}

void dfs(int x) {
    int next;
    visited[x] = true;
    cout << x << ' ';
    for(int i = 0; i < graph[x].size(); i++) {
        next = graph[x][i];
        if(!visited[next]) dfs(next);
    }
}

void bfs(int x) {
    int front;
    int next;
    queue<int> q;

    visited[x] = true;
    q.push(x);

    while(!q.empty()) {
        front = q.front();
        q.pop();
        cout << front << ' ';
        for(int i = 0; i < graph[front].size(); i++) {
            next = graph[front][i];
            if (!visited[next]) {
                q.push(graph[front][i]);
                visited[next] = true;
            }
        }
    }
}

void solve() {
    fill(visited, visited + n + 1, false);
    dfs(v);
    cout << endl;
    fill(visited, visited + n + 1, false);
    bfs(v);
    cout << endl;
    delete[] visited; 
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    solve();
}