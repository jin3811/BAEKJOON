#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

template<class T>
class MSTree {
	size_t len, elemCnt;
	vector<vector<T>> tree;

	int _range_greater(int st, int ed, int cur, int left, int right, int k) {
		if (left > ed || right < st) return 0;

		// 범위 내에 있다면
		if (left <= st && ed <= right) {
			return tree[cur].end() - upper_bound(tree[cur].begin(), tree[cur].end(), k); 
		}

		// flag.아니면 서브트리 확인
		int mid = (st + ed) >> 1;
		return _range_greater(st, mid, cur * 2, left, right, k) + _range_greater(mid + 1, ed, cur * 2 + 1, left, right, k);
	}

public:
	MSTree(const vector<T>& container) {
		init(container);
	}

	MSTree() {}

	void init(const vector<T>& container) {
		elemCnt = container.size();
		int height = (int)ceil(log2(elemCnt));
		len = 1UL << height + 1;
		tree.resize(len);

		for(int i = 0; i < elemCnt; i++) {
			tree[len/2 + i].push_back(container[i]);
		}
		for(int i = len/2 - 1; i; --i) {
			tree[i].resize(tree[i * 2].size() + tree[i * 2 + 1].size());
			merge(ALL(tree[i * 2]), ALL(tree[i * 2 + 1]), tree[i].begin());
		}
	}

	int range_greater(int i, int j, int k) {
		return _range_greater(1, len/2, 1, i, j, k);
	}
};

int n, m;
vector<int> a;
vector<tuple<int,int,int>> query;

void input() {
	cin >> n;
	a.resize(n);
	for(int& x : a) cin >> x;
	cin >> m;
	query.resize(m);
	for(auto& [i, j, k] : query) cin >> i >> j >> k;
}

void sol() {
	MSTree mstree(a);

	for(auto& [i, j, k] : query) {
		cout << mstree.range_greater(i, j, k) << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}