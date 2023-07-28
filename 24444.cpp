#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n, r;
vector<vector<int>> graph;

void input() {
	int a, b, m;

	cin >> n >> m >> r;
	graph.resize(n + 1);
	while (m--) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (auto& node : graph) {
		sort(ALL(node));
	}
}

void bfs(int start, int visit[]){
	queue<int> q;
	int cnt = 1;
	
	q.push(start);
	visit[start] = cnt++;

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		for(int nxt : graph[cur]) {
			if (visit[nxt] == 0) {
				q.push(nxt);
				visit[nxt] = cnt++;
			}
		}
	}
}

void sol() {
	int visit[n + 1] = {0};
	bfs(r, visit);
	for (int i = 1; i <= n; i++) {
		cout << visit[i] << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}