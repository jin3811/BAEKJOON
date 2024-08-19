#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

template<class T>
class SegTree {
	size_t len = 1;
	vector<T> origin;
	T* tree;

	T _init(int st, int ed, int cur) {
		if (st == ed) {
			return tree[cur] = origin[st - 1];
		}
		int mid = (st + ed) >> 1;
		return tree[cur] = _init(st, mid, cur*2) + _init(mid + 1, ed, cur * 2 + 1);
	}

	void _update(int st, int ed, int cur, int index, T diff) {
		if (index < st || index > ed) return;

		tree[cur] += diff;

		if (st == ed) return;

		int mid = (st + ed) >> 1;
		_update(st, mid, cur * 2, index, diff);
		_update(mid + 1, ed, cur * 2 + 1, index, diff);
	}

	T _rangeSum(int st, int ed, int cur, int left, int right) {
		if (left > ed || right < st) return 0;

		if (left <= st && ed <= right) return tree[cur];

		int mid = (st + ed) >> 1;
		return _rangeSum(st, mid, cur * 2, left, right) + _rangeSum(mid + 1, ed, cur * 2 + 1, left, right);
	}

public:
	SegTree(const vector<T>& container) {
		origin = container;

		len = 1UL << (int)ceil(log2(container.size())) + 1;
		tree = new T[len + 1];

		_init(1, origin.size(), 1);
	}

	void update(int index, T newNum) {
		_update(1, origin.size(), 1, index, newNum - origin[index-1]);
		origin[index-1] = newNum;
	}

	T rangeSum(int left, int right) {
		return _rangeSum(1, origin.size(), 1, left, right);
	}

	~SegTree() { delete[] tree; }
};

int n, m, k;
vector<ll> nums;
vector<tuple<ll, ll, ll>> query;

void input() {
	cin >> n >> m >> k;
	nums.resize(n), query.resize(m + k);
	
	for (ll& n : nums) cin >> n;
	for (auto& [q, a, b] : query) cin >> q >> a >> b;
}

void sol() {
	SegTree<ll> segTree(nums);

	for (auto& [q, a, b] : query) {
		if (q == 1) {
			segTree.update(a, b);
		}
		else {
			cout << segTree.rangeSum(a, b) << endl;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}