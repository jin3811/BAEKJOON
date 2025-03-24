#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;
using ll = long long;
using tii = tuple<int,int,int>;

typedef struct Disjoint_set{
	int* tree;
	Disjoint_set(int n) {
		tree = new int[n + 1];
		memset(tree, 0xff, sizeof(int) * (n + 1));
	}

	void merge(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		tree[b] = a;
	}

	int find(int a) {
		if (tree[a] < 0) return a;
		return tree[a] = find(tree[a]);
	}

	~Disjoint_set() { delete[] tree; }
} DS;

int n, m;
vector<tii> path;
vector<vector<pair<int,int>>> graph;
ll ans;

void input() {
	cin >> n >> m;
	path.resize(m);
	graph.resize(n + 1);
	for(auto& [c, a, b] : path) {
		cin >> a >> b >> c;
		ans += c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
}

bool visited[100001];

void dfs(int cur, int prev) {
	visited[cur] = true;
	for(auto& [nxt, c] : graph[cur]) {
		if (nxt == prev || visited[nxt]) continue;
		dfs(nxt, cur);
	}
}

void sol() {
	dfs(1, 0);
	if (find(visited + 1, visited + n + 1, false) != visited + n + 1) {
		cout << -1;
		return;
	}

	DS ds(n);
	int e = 0;
	sort(ALL(path));

	for(auto& [c, a, b] : path) {
		if (e == n - 1) break;

		int ra = ds.find(a), rb = ds.find(b);
		if (ra + rb == -2 || ra != rb) {
			ans -= c, ++e;
			ds.merge(a, b);
		}
	}
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}