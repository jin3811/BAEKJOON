#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n,r;
vector<vector<int>> graph;

void input() {
	int a, b, m;
	cin >> n >> m >> r;
	graph.resize(n + 1);
	while(m--) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for_each(ALL(graph), [](vector<int>& node){ sort(ALL(node)); });
}

void dfs(int cur, int depth, vector<int>& ans) {
	if (ans[cur] != -1) return;
	ans[cur] = depth;

	for(int& nxt : graph[cur]) {
		dfs(nxt, depth + 1, ans);
	}
}

void sol() {
	vector<int> ans(n+1, -1);
	dfs(r, 0, ans);
	for(int i = 1; i <= n; i++) cout << ans[i] << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}