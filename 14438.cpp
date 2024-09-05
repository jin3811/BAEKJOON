#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

template<class T>
class SegTree {
	size_t len = 1;
	vector<T> origin;
	vector<T> tree;

	T _init(int st, int ed, int cur) {
		if (st == ed) {
			return tree[cur] = origin[st - 1];
		}

		int mid = (st + ed) >> 1;

		// 문제에 따라 해당 부분은 처리를 다르게 해야함(ex. 구간 최대/최소).
		return tree[cur] = min(_init(st, mid, cur*2), _init(mid + 1, ed, cur * 2 + 1));
	}

	T _update(int st, int ed, int cur, int index, int newNum) {
		// 범위 검사
		if (index < st || index > ed) return tree[cur];

		// 리프노드이면 값만 수정하면 된다.
		if (st == ed) {
			tree[cur] = newNum;
			return tree[cur];
		}

		// 리프노드가 아니면 서브트리로 재귀하면서, 최솟값 갱신
		int mid = (st + ed) >> 1;
		return tree[cur] = min(_update(st, mid, cur * 2, index, newNum),
			 			_update(mid + 1, ed, cur * 2 + 1, index, newNum));
	}

	T _rangeMin(int st, int ed, int cur, int left, int right) {
		// 범위를 넘어가면 무시
		if (left > ed || right < st) return INT32_MAX;

		// 범위 내에 있다면
		if (left <= st && ed <= right) return tree[cur];

		// 아니면 서브트리 확인
		int mid = (st + ed) >> 1;
		return min(_rangeMin(st, mid, cur * 2, left, right), _rangeMin(mid + 1, ed, cur * 2 + 1, left, right));
	}

public:
	SegTree(const vector<T>& container) {
		init(container);
	}

	SegTree() {}

	void init(const vector<T>& container) {
		// 원본 저장
		origin = container;

		// 트리 사이즈 구해서 할당하기
		len = 1UL << (int)ceil(log2(container.size())) + 1;
		tree = vector<T>(len + 1);

		// 트리 초기화
		_init(1, origin.size(), 1);
	}

	void update(int index, int newNum) {
		_update(1, origin.size(), 1, index, newNum);
		origin[index-1] = newNum;
	}

	T rangeMin(int left, int right) {
		return _rangeMin(1, origin.size(), 1, left, right);
	}
};

using ti3 = tuple<int,int,int>;

int n, m;
SegTree<int> seg;
vector<ti3> querys;

void input() {
	vector<int> origin;
	cin >> n;
	origin.resize(n);
	for(int& x : origin) cin >> x;
	seg.init(origin);
	cin >> m;
	querys.resize(m);
	for(auto& [q, a, b] : querys) cin >> q >> a >> b;
}

void sol() {
	for(auto& [q, a, b] : querys) {
		if (q == 1) {
			seg.update(a, b);
		}
		else {
			cout << seg.rangeMin(a, b) << endl;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}