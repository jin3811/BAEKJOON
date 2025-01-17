#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
vector<vector<int>> graph;
vector<int> parent;

void input() {
	int a, b, cnt;
	cin >> n;
	cnt = n;
	graph.resize(n + 1);
	parent.resize(n + 1, -1);
	while(--cnt){
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}
void dfs(int prev, int cur) {
	parent[cur] = prev;

	for(int nxt : graph[cur]) {
		if (nxt == prev) continue;
		dfs(cur, nxt);
	}
}

void sol() {
	dfs(-1, 1);
	for(int i = 2; i <= n; i++) {
		cout << parent[i] << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}