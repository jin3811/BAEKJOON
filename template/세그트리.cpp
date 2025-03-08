/**
 * 재귀 방식의 세그먼트 트리 구현체
 * 구간 합을 기준으로 구현한 예시이다.
 * 필요에 따라 구현을 수정해야한다(flag).
 *
 * 세그트리 사용 예
 * 구간 합 : boj/2042, boj/2268, 
 * 구간 곱 : 
 * 구간 최대최소 : boj/14438, 
 */
#include <iostream>
#include <cmath>
#include <vector>
#define ALL(X) X.begin(), X.end()

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

		// flag. 문제에 따라 해당 부분은 처리를 다르게 해야함(ex. 구간 최대/최소).
		return tree[cur] = _init(st, mid, cur*2, container) + _init(mid + 1, ed, cur * 2 + 1, container);
	}

	T _update(int st, int ed, int cur, int index, T newVal) {
		// flag. 범위 검사
		if (index < st || index > ed) return tree[cur];

		// 리프노드면 수정사항만 적용한다.
		if (st == ed) {
			tree[cur] = newVal;
			return tree[cur];
		}

		// flag. 리프노드가 아니면 서브트리로 재귀하며 값을 업데이트
		int mid = (st + ed) >> 1;
		return tree[cur] = _update(st, mid, cur * 2, index, newVal) 
					+ _update(mid + 1, ed, cur * 2 + 1, index, newVal);
	}

	T _rangeSum(int st, int ed, int cur, int left, int right) {
		// flag. 범위를 넘어가면 무시
		if (left > ed || right < st) return 0;

		// 범위 내에 있다면
		if (left <= st && ed <= right) return tree[cur];

		// flag.아니면 서브트리 확인
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
		len = 1UL << (int)ceil(log2(this->elemCnt)) + 1;
		tree = vector<T>(len);

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

/**
 * 비재귀 방식의 세그먼트 트리
 */

// TODO : 비재귀 구현

/**
 * 재귀 방식 머지 소트 트리
 * 
 * 세그먼트 트리에 머지소트를 결합한 자료구조
 */
template<class T>
class MSTree {
	size_t len, elemCnt;
	vector<vector<T>> tree;

    void _init(int st, int ed, int cur, const vector<T>& container) {
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
		// 범위 밖이면 제외
		if (left > ed || right < st) return 0;

		// 범위 내에 있다면
		if (left <= st && ed <= right) {
			return tree[cur].end() - upper_bound(tree[cur].begin(), tree[cur].end(), k); 
		}

		// 아니면 서브트리 확인
		int mid = (st + ed) >> 1;
		return _range_greater(st, mid, cur * 2, left, right, k) + _range_greater(mid + 1, ed, cur * 2 + 1, left, right, k);
	}

public:
	MSTree(const vector<T>& container) {
		init(container);
	}

	void init(const vector<T>& container) {
		elemCnt = container.size();
		// 트리 사이즈 구해서 할당하기
		int height = (int)ceil(log2(elemCnt));
		len = 1UL << height + 1;
		tree.resize(len);

		// 트리 초기화
		_init(1, elemCnt, 1, container);
	}

	int range_greater(int i, int j, int k) {
		return _range_greater(1, elemCnt, 1, i, j, k);
	}
};

/**
 * 비재귀 방식 머지 소트 트리
 * 
 * 아직 구현 안됨
 */

template<class T>
class MSTree {
	size_t len, elemCnt;
	vector<vector<T>> tree;

	int _range_greater(int st, int ed, int cur, int left, int right, int k) {
		// if (left > ed || right < st) return 0;

		// // 범위 내에 있다면
		// if (left <= st && ed <= right) {
		// 	return tree[cur].end() - upper_bound(tree[cur].begin(), tree[cur].end(), k); 
		// }

		// // flag.아니면 서브트리 확인
		// int mid = (st + ed) >> 1;
		// return _range_greater(st, mid, cur * 2, left, right, k) + _range_greater(mid + 1, ed, cur * 2 + 1, left, right, k);

		// TODO : 구현하기. 위의 주석은 비재귀저장방식에 맞추기 위해 작성한 재귀적 방식
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
		// return _range_greater(1, len/2, 1, i, j, k);
		// TODO : 구현하기. 위의 주석은 비재귀저장방식에 맞추기 위해 작성한 재귀적 방식
	}
};