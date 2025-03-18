#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

template<class T>
class SegTree {
	size_t len;
	size_t elemCnt;
	vector<T> tree;

	T _init(int st, int ed, int cur, const vector<T>& container) {
		if (st == ed) {
			return tree[cur] = container[st - 1];
		}

		int mid = (st + ed) >> 1;

		return tree[cur] = min(_init(st, mid, cur*2, container), _init(mid + 1, ed, cur * 2 + 1, container));
	}

	T _range(int st, int ed, int cur, int left, int right) {
		if (left > ed || right < st) return INT32_MAX;

		if (left <= st && ed <= right) return tree[cur];

		int mid = (st + ed) >> 1;
		return min(_range(st, mid, cur * 2, left, right), _range(mid + 1, ed, cur * 2 + 1, left, right));
	}

public:
	SegTree(const vector<T>& container) {
		init(container);
	}

	void init(const vector<T>& container) {
		elemCnt = container.size();
		len = 1UL << (int)ceil(log2(this->elemCnt)) + 1;
		tree = vector<T>(len);
		_init(1, elemCnt, 1, container);
	}

	T range(int left, int right) {
		return _range(1, elemCnt, 1, left, right);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<int> i(n);
	vector<pair<int,int>> q(m);
	for(int& x : i) cin >> x;
	for(auto& [l, r] : q) cin >> l >> r;
	
	SegTree seg(i);
	for(auto& [l, r] : q) {
		cout << seg.range(l, r) << endl;
	}
}