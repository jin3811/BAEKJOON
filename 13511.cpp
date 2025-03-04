/**
 * boj/13511
 * 
 * 처음에는 희소행렬인줄 알았는데, 도저히 궁금함을 못참고 태그 까서 LCA라는걸 알게됨 아...
 * 
 * 쿼리 1이던 2던 어쨌든 LCA를 찾는것이 먼저이다.
 * 
 * 쿼리 1은 LCA를 찾은 후, 두 노드가 LCA까지 가기 위한 비용을 합친다
 * 쿼리 2는 LCA를 찾은 후, u -> LCA로 가기 위한 거리가 k보다 작다면 LCA -> v로 가는 곳에 있고, 그렇지 않다면 u -> LCA로 가는 길에 있다.
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define MAX_A 4 // log(max(n)) = log(100k) = 17이니 여유롭게 20으로 설정

int n,m;
vector<vector<pair<int,ll>>> tree, graph;
vector<int> depths;
vector<tuple<int,int,int,int>> query;

void make_tree(int st, int p, int c, int h) {
	tree[st][0] = {p, c}, depths[st] = h;

	for(auto& [g, cc] : graph[st]) {
		if (g == p) continue;
		make_tree(g, st, cc, h + 1);
	}
}

void make_ancestor() {
	for (int ancestor = 1; ancestor <= MAX_A; ancestor++) {
		for (int node = 1; node <= n; node++) {
			tree[node][ancestor].first = tree[tree[node][ancestor - 1].first][ancestor - 1].first;
			tree[node][ancestor].second = tree[tree[node][ancestor - 1].first][ancestor - 1].second + tree[node][ancestor - 1].second;
		}
	}
}

void input(){
	int a, b, c;
	cin >> n;
	graph.resize(n + 1);
	tree.resize(n + 1, vector<pair<int,ll>>(MAX_A + 1));
	depths.resize(n + 1, -1);
	for (int i = 1; i < n; i++){
		cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}
	cin >> m;
	query.resize(m);
	for(auto& [q, u, v, k] : query) {
		cin >> q >> u >> v;
		if (q == 2) cin >> k;
	}
	make_tree(1, 0, 0, 1);
	make_ancestor();
}

// lca, cost, u->lca, v->lca
tuple<int, ll, int, int> get_lca(int u, int v) {
	bool swap_flag = false;
	tuple<int, ll, int, int> ans;
	auto& [lca, cost, du, dv] = ans;
	du = 1, dv = 1;

	// u노드를 v노드의 높이로 끌어올린다.
	if (depths[u] < depths[v]){
		swap(u, v);
		swap_flag = true;
	}

	int dh = depths[u] - depths[v];
	swap_flag ? dv += dh : du += dh;

	for (int i = MAX_A; i >= 0 && dh; i--) {
		if (dh >= (1 << i)) {
			cost += 1LL * tree[u][i].second;
			u = tree[u][i].first;
			dh -= (1 << i);
		}
	}

	if (u != v) {
		for (int i = MAX_A; i >= 0; i--) {
			if (tree[u][i].first != 0 && tree[u][i].first != tree[v][i].first) {
				cost += 1LL * tree[u][i].second + tree[v][i].second;
				u = tree[u][i].first;
				v = tree[v][i].first;
				du += 1 << i, dv += 1 << i;
			}
		}
		cost += 1LL * tree[u][0].second + tree[v][0].second;
		++du, ++dv;
	}

	lca = tree[v][0].first;

	return ans;
}

void sol() {
	for(auto& [q, target, goal, k] : query) {
		auto [lca, cost, dt, dg] = get_lca(target, goal);
		// cout << "lca : " << lca << endl << "cost : " << cost << endl << "u -> lca : " << dt << endl << "v -> lca : " << dg << endl << endl;
		if (q == 1) {
			cout << cost;
		}
		else {
			if (dt >= k) {
				--k;
				for(int i = MAX_A; i >= 0 && k; i--) {
					if (k >= 1 << i) {
						target = tree[target][i].first;
						k -= 1 << i;
					}
				}
				cout << target;
			}
			else {
				k = dg - (k - dt) - 1;
				for(int i = MAX_A; i >= 0 && k; i--) {
					if (k >= 1 << i) {
						goal = tree[goal][i].first;
						k -= 1 << i;
					}
				}
				cout << goal;
			}
		}
		cout << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}