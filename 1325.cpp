#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;

void input() {
    int a, b;
    cin >> n >> m;
    graph.resize(n + 1);
    for (int i = 1 ; i <= m; i++) {
        cin >> a >> b;
        graph[b].push_back(a);
    }
}

int dfs(int n, bool visited[]) {
    if (visited[n]) {
        return 0;
    }
    int result = 1;
    visited[n] = true;
    for (int x : graph[n]) {
        result += dfs(x, visited);
    }
    return result;
}

void sol() {
    int arr[n] = {0};
    bool visited[n + 1];
    int maxCnt = 0;

    for (int i = 0; i < n; i++) {
        fill(visited, visited + n + 1, false);
        arr[i] = dfs(i + 1, visited);
        maxCnt = max(arr[i], maxCnt);
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == maxCnt) cout << i + 1 << " ";
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}