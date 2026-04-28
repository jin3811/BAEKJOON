#include <bits/stdc++.h>
#define ALL(X) X.begin(),X.end()
#define endl '\n'
using namespace std;
using ll = long long;
using ti4 = tuple<int,int,int,int>;

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

		// 리프노드면 수정사항만 적용한다.
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
		// 트리 사이즈 구해서 할당하기
		len = 1UL << (int)ceil(log2(container.size())) + 1;
		tree = vector<T>(len + 1);

		// 트리 초기화
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

int n, q;
vector<ti4> querys;
SegTree<ll> seg;

void input() {
    cin >> n >> q;
    vector<ll> v(n);
    querys.resize(q);
    for(ll& x : v) cin >> x;
    for(auto&[x, y, a, b] : querys) {
        cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);
    }
    seg.init(v);
}

void sol() {
    for(auto& [x, y, a, b] : querys) {
        cout << seg.rangeSum(x, y) << endl;
        seg.update(a, b);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    input();
    sol();
}