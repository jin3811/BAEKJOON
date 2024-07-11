#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using ll = int64_t;
using namespace std;

int n, c, w;
vector<int> tree;
ll answer;
vector<bool> selected;

void input() {
	cin >> n >> c >> w;
	tree.resize(n);
	selected.resize(n, false);
	for (int& t : tree) cin >> t;
	sort(ALL(tree));
}

void backtracking(int lim, int cnt) {
	if (cnt >= lim) {
		ll tmp = 0;
		for (int i = 0; i < n; i++) {
			if (!selected[i]) continue;

            for (int len = 1; len <= tree[n-2]; len++) {
                tmp -= 1L * c * ((tree[i] - 1) / len);
                tmp += 1L * i * w * (tree[i] / len);
            }
		}
		answer = max(answer, tmp);
	}

	for (int i = 0; i < n; i++) {
		selected[i] = true;
		backtracking(lim, cnt+1);
		selected[i] = false;
	}
}

void sol() {
	for (int i = 1; i <= n; i++) {
		backtracking(i, 0);
	}
	cout << answer;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}