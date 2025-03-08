#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

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