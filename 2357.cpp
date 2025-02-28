#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

template<class T>
class SegTree {
	size_t len, elemCnt;
	vector<T> tree;
	int (*f)(int,int);
	int err;

	T _init(int st, int ed, int cur, const vector<T>& container) {
		if (st == ed) {
			return tree[cur] = container[st - 1];
		}

		int mid = (st + ed) >> 1;

		return tree[cur] = f(_init(st, mid, cur*2, container), _init(mid + 1, ed, cur * 2 + 1, container));
	}

	T _range(int st, int ed, int cur, int left, int right) {
		if (left > ed || right < st) return err;

		if (left <= st && ed <= right) return tree[cur];

		int mid = (st + ed) >> 1;
		return f(_range(st, mid, cur * 2, left, right), _range(mid + 1, ed, cur * 2 + 1, left, right));
	}

public:
	SegTree(const vector<T>& container, int (*f)(int,int), int err) {
		this->err = err;
		this->f = f;
		elemCnt = container.size();

		len = 1UL << ((int)ceil(log2(container.size())) + 1);
		tree = vector<T>(len + 1);

		_init(1, elemCnt, 1, container);
	}

	T range(int left, int right) {
		return _range(1, elemCnt, 1, left, right);
	}
};

int n, m;
vector<int> container;
vector<pair<int,int>> query;

void input() {
	cin >> n >> m;
	container.resize(n), query.resize(m);

	for(int& x : container) cin >> x;
	for(auto& [st, ed] : query) cin >> st >> ed;
}

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

void sol() {
	SegTree seg_max(container, max, -1), seg_min(container, min, 1234567890);

	for(auto& [st, ed] : query) {
		cout << seg_min.range(st, ed) << ' ' << seg_max.range(st, ed) << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}