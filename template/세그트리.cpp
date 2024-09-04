#include <iostream>
#include <cmath>
#include <vector>

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
		return tree[cur] = _init(st, mid, cur*2) + _init(mid + 1, ed, cur * 2 + 1);
	}

	void _update(int st, int ed, int cur, int index, int diff) {
		// 범위 검사
		if (index < st || index > ed) return;

		// 값 업데이트
		tree[cur] += diff;

		// 리프노드이면 되돌아간다.
		if (st == ed) return;

		// 리프노드가 아니면 서브트리로 재귀
		int mid = (st + ed) >> 1;
		_update(st, mid, cur * 2, index, diff);
		_update(mid + 1, ed, cur * 2 + 1, index, diff);
	}

	T _rangeSum(int st, int ed, int cur, int left, int right) {
		// 범위를 넘어가면 무시
		if (left > ed || right < st) return 0;

		// 범위 내에 있다면
		if (left <= st && ed <= right) return tree[cur];

		// 아니면 서브트리 확인
		int mid = (st + ed) >> 1;
		return _rangeSum(st, mid, cur * 2, left, right) + _rangeSum(mid + 1, ed, cur * 2 + 1, left, right);
	}

public:
	SegTree(const vector<T>& container) {
		// 원본 저장
		origin = container;

		// 트리 사이즈 구해서 할당하기
		len = 1UL << (int)ceil(log2(container.size())) + 1;
		tree = vector<T>(len + 1);

		// 트리 초기화
		_init(1, origin.size(), 1);
	}

	void update(int index, int newNum) {
		_update(1, origin.size(), 1, index, newNum - origin[index-1]);
		origin[index-1] = newNum;
	}

	T rangeSum(int left, int right) {
		return _rangeSum(1, origin.size(), 1, left, right);
	}

	void print() { 
		for (int i = 1; i <= len; i++) cout << tree[i] << ' ';
	}
	~SegTree() { delete[] tree; }
};