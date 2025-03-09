#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

class MSTree {
	size_t len, elemCnt;
	vector<vector<int>> tree;

	void _init(int st, int ed, int cur, const vector<int>& container) {
		if (st == ed) {
			tree[cur].push_back(container[st - 1]);
			return;
		}

		int mid = (st + ed) / 2;
		int lnode = cur * 2;
		int rnode = cur * 2 + 1;
		_init(st, mid, lnode, container);
		_init(mid + 1, ed, rnode, container);

		tree[cur].resize(tree[lnode].size() + tree[rnode].size());
		merge(ALL(tree[lnode]), ALL(tree[rnode]), tree[cur].begin());
	}

	int _range_greater(int st, int ed, int cur, int left, int right, int k) {
		if (left > ed || right < st) return 0;

		if (left <= st && ed <= right) {
			return tree[cur].end() - upper_bound(tree[cur].begin(), tree[cur].end(), k); 
		}

		int mid = (st + ed) >> 1;
		return _range_greater(st, mid, cur * 2, left, right, k) + _range_greater(mid + 1, ed, cur * 2 + 1, left, right, k);
	}

public:
	MSTree(const vector<int>& container) {
		init(container);
	}

	void init(const vector<int>& container) {
		elemCnt = container.size();
		int height = (int)ceil(log2(elemCnt));
		len = 1UL << height + 1;
		tree.resize(len);

		_init(1, elemCnt, 1, container);
	}

	int range_greater(int i, int j, int k) {
		return _range_greater(1, elemCnt, 1, i, j, k);
	}
};

int n, m;
vector<int> v;
vector<tuple<int,int,int>> query;

void input() {
	cin >> n; v.resize(n);
	for(int& x : v) cin >> x;
	cin >> m; query.resize(m);
	for(auto& [a, b, c] : query) cin >> a >> b >> c;
}

void sol() {
	MSTree mst(v);
	int ans = 0;

	for(auto& [a, b, c] : query) {
		int i = a^ans, j = b^ans, k = c^ans;
		ans = mst.range_greater(i, j, k);
		cout << ans << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}