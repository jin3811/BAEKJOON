#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

vector<vector<int>> graph;
bool visited[500];

void input() {
	int n, m, a, b;
	cin >> n >> m;
	graph.resize(n + 1);
	while(m--) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

int dfs(int x, int depth) {
	visited[x] = true;

	if (depth >= 2) {
		return 0;
	}

	int cnt = 0;

	for (int next_friend : graph[x]) {
		if (!visited[next_friend]) {
			cnt += 1 + dfs(next_friend, depth + 1);
		}
		else {
			cnt += dfs(next_friend, depth + 1);
		}
	}
	return cnt;
}

void sol() {
	cout << dfs(1, 0);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}