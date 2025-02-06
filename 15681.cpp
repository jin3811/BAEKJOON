#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, r, q;
vector<vector<int>> tree;
vector<int> query, child;

void input() {
	int a, b;

	cin >> n >> r >> q;
	tree.resize(n + 1), query.resize(q), child.resize(n + 1, 1);

	for(int i = 1; i < n; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	for(int& q : query) cin >> q;
}

int dfs(int parent, int cur) {
	for(int& c : tree[cur]) {
		if (c == parent) continue;
		child[cur] += dfs(cur, c);
	}
	return child[cur];
}

void sol() {
	dfs(-1, r);
	for(int& q : query) cout << child[q] << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}