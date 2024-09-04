#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ul = uint64_t;
using tul3 = tuple<ul,ul,ul>;

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

		return tree[cur] = _init(st, mid, cur*2, container) + _init(mid + 1, ed, cur * 2 + 1, container);
	}

	T _update(int st, int ed, int cur, int index, T newVal) {
		if (index < st || index > ed) return tree[cur];

		if (st == ed) {
			tree[cur] = newVal;
			return tree[cur];
		}

		int mid = (st + ed) >> 1;
		return tree[cur] = _update(st, mid, cur * 2, index, newVal) 
					+ _update(mid + 1, ed, cur * 2 + 1, index, newVal);
	}

	T _rangeSum(int st, int ed, int cur, int left, int right) {
		if (left > ed || right < st) return 0;

		if (left <= st && ed <= right) return tree[cur];

		int mid = (st + ed) >> 1;
		return _rangeSum(st, mid, cur * 2, left, right) +
				_rangeSum(mid + 1, ed, cur * 2 + 1, left, right);
	}

public:
	SegTree(const vector<T>& container) {
		init(container);
	}

	SegTree() {}

	void init(const vector<T>& container) {
		elemCnt = container.size();
		len = 1UL << (int)ceil(log2(container.size())) + 1;
		tree = vector<T>(len + 1);

		_init(1, elemCnt, 1, container);
	}

	void update(int index, T newVal) {
		_update(1, elemCnt, 1, index, newVal);
	}

	T rangeSum(int left, int right) {
		return _rangeSum(1, elemCnt, 1, left, right);
	}

	void print() { 
		for (int i = 1; i <= len; i++) cout << tree[i] << ' ';
	}
};

int n, m;
vector<ul> v;
vector<tul3> querys;

void input() {
	cin >> n >> m;
	v.resize(n, 0ULL);
	querys.resize(m);
	for(auto& [q, a, b] : querys) {
		cin >> q >> a >> b;
	}
}

void sol() {
	SegTree<ul> seg(v);
	for(auto& [q, a, b] : querys) {
		if(q) {
			seg.update(a, b);
		}
		else {
			if (a > b) swap(a, b);
			cout << seg.rangeSum(a, b) << endl;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}