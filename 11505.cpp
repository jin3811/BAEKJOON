#include <bits/stdc++.h>
#define endl '\n'
#define MOD 1000000007
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

		return tree[cur] = (_init(st, mid, cur*2, container) * _init(mid + 1, ed, cur * 2 + 1, container)) % MOD;
	}

	T _update(int st, int ed, int cur, int index, T newVal) {
		if (index < st || index > ed) return tree[cur];

		if (st == ed) {
			tree[cur] = newVal;
			return tree[cur];
		}

		int mid = (st + ed) >> 1;
		return tree[cur] = (_update(st, mid, cur * 2, index, newVal) 
					* _update(mid + 1, ed, cur * 2 + 1, index, newVal)) % MOD;
	}

	T _rangeMul(int st, int ed, int cur, int left, int right) {
		if (left > ed || right < st) return 1;

		if (left <= st && ed <= right) return tree[cur];

		int mid = (st + ed) >> 1;
		return (_rangeMul(st, mid, cur * 2, left, right) *
				_rangeMul(mid + 1, ed, cur * 2 + 1, left, right)) % MOD;
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

	T rangeMul(int left, int right) {
		return _rangeMul(1, elemCnt, 1, left, right);
	}

	void print() { 
		for (int i = 1; i <= len; i++) cout << tree[i] << ' ';
	}
};

using ul = uint64_t;

int n;
SegTree<ul> seg;
vector<tuple<int,int,int>> querys;

void input() {
	vector<ul> origin;
	int tmp1, tmp2;

	cin >> n >> tmp1 >> tmp2;

	origin.resize(n);
	querys.resize(tmp1 + tmp2);

	for(ul& x : origin) cin >> x;

	seg.init(origin);

	for(auto& [q, a, b] : querys) cin >> q >> a >> b;
}

void sol() {
	for(auto& [q, a, b] : querys) {
		if (q == 1) {
			seg.update(a, b);
		}
		else {
			cout << seg.rangeMul(a, b) << endl;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}