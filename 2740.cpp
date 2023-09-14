#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n, m, k;
vector<vector<int>> a, b;

void input() {
	cin >> n >> m;
	a.resize(n);
	for (auto& row : a) {
		row.resize(m);
		for (int& x : row) {
			cin >> x;
		}
	}

	cin >> m >> k;
	b.resize(m);
	for (auto& row : b) {
		row.resize(k);
		for (int& x : row) {
			cin >> x;
		}
	}
}

void sol() {
	vector<vector<int>> answer(n, vector<int>(k, 0));
	for (int ay = 0; ay < n; ay++) {
		for (int bx = 0; bx < k; bx++) {
			for (int ax = 0; ax < m; ax++) {
				answer[ay][bx] += a[ay][ax] * b[ax][bx];
			}
		}
	}

	for (auto& row : answer) {
		for (int x : row) {
			cout << x << " ";
		}
		cout << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}