#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

vector<vector<int>> graph;
int n, m, r;

void input() {
	int a, b;
	cin >> n >> m >> r;
	graph.resize(n + 1);
	while (m--) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (auto& node_list : graph) {
		sort(ALL(node_list), greater<>());
	}
}

void bfs(int start, int nodes[]) {
	int visit_cnt = 1;
	bool visited[n + 1] = {false, };
	queue<int> q;

	visited[start] = true;
	nodes[start] = visit_cnt++;
	q.push(start);

	while(!q.empty()) {
		int curr = q.front();
		q.pop();

		for(int next_node : graph[curr]) {
			if (!visited[next_node]) {
				visited[next_node] = true;
				nodes[next_node] = visit_cnt++;
				q.push(next_node);
			}
		}
	}
}

void sol() {
	int nodes[n + 1] = {0, };
	bfs(r, nodes);
	for (int i = 1; i <= n; i++) {
		cout << nodes[i] << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}