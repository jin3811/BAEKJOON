#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

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
};

int v, e;
vector<tuple<int,int,int>> path;

void input() {
	cin >> v >> e;
	path.resize(e);
	for(auto& [d, a, b] : path) cin >> a >> b >> d;
}

void sol() {
	Disjoint_set ds(v);
	int edge = 0, answer = 0;

	sort(ALL(path));
	for(auto& [dist, st, ed] : path) {
		if (edge == v - 1) break;

		int rst = ds.find(st), red = ds.find(ed);
		if (rst + red == -2 || rst != red) {
			answer += dist;
			edge++;
			ds.merge(st, ed);
		}
	}
	cout << answer;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}