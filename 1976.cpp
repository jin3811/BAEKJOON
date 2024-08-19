#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> route;

void input() {
	cin >> n >> m;
	graph.resize(n + 1, vector<int>(n + 1));
	route.resize(m);
	for(int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
		}
	}
	for (int& r : route) {
		cin >> r;
	}
}

bool check_path_exists(int st, int ed, bool visited[]) {
	visited[st] = true;

	if (graph[st][ed]) return true;
    else if (st == ed) return true;
	else {
		for (int i = 1; i <= n; i++) {
			if (!graph[st][i] || visited[i]) continue;
			
			if (check_path_exists(i, ed, visited)) {
				graph[st][ed] = 1;
                graph[ed][st] = 1;
				return true;
			}
		}
	}
	return false;
}

void sol() {
	for (int i = 1; i < m; i++) {
		bool visited[n + 1] = {false};
		if (!check_path_exists(route[i - 1], route[i], visited)) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}