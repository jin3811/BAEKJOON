#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n, m;
vector<pair<string, int>> query;

void input() {
	cin >> m >> n;
	query.resize(n);
	for (auto& [q, d] : query) {
		cin >> q >> d;
	}
}

void sol() {
	pair<int, int> pos{0, 0};
	int dir = 0; // 0 ~ 3 순서대로 오, 위, 왼, 아

	for (auto& [q, d] : query) {
		if (q[0] == 'M') {
			auto& [h, v] = pos;
			if (dir == 0) {
				h += d;
			}
			else if (dir == 2) {
				h -= d;
			}
			else if (dir == 1) {
				v += d;
			}
			else if (dir == 3) {
				v -= d;
			}
			else {
				assert(true);
			}
			if (h < 0 || h > m || v < 0 || v > m) {
				cout << -1;
				return;
			}
		}
		else {
			if (d == 0) dir = (dir + 1) % 4;
			else dir = (dir + 3) % 4;
		}
	}
	auto& [h, v] = pos;
	cout << h << ' ' << v;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}