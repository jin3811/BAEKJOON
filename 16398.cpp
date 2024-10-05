#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;
using tl3 = tuple<int,int,int>;

int n;
vector<tl3> path;

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
} Disjoint_set;

void input() {
	int dist;
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> dist;
			if (i < j) {
				path.push_back({dist, i, j});
			}
		}
	}
}

void sol() {
	Disjoint_set ds(n);
	int edge = 0;
	uint64_t answer = 0;
	
	sort(ALL(path));
	for(auto& [dist, st, ed] : path) {
		if (edge == n - 1) break;

		int rst = ds.find(st), red = ds.find(ed);
		if (rst + red == -2 || rst != red) {
			answer += 1ULL * dist;
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
