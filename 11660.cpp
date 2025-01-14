#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m;
vector<vector<int>> table;
vector<tuple<int,int,int,int>> query;

void input() {
	cin >> n >> m;
	table.resize(n+1, vector<int>(n+1));
	query.resize(m);

	for(int x = 1; x <= n; x++) {
		for(int y = 1; y <= n; y++) {
			cin >> table[x][y];
		}
	}

	for(auto& [x1, y1, x2, y2] : query) {
		cin >> x1 >> y1 >> x2 >> y2;
	}

	for(auto& row : table) {
		for(int i = 1; i <= n; i++) {
			row[i] += row[i - 1];
		}
	}
}

void sol() {
	int ans;
	for(auto [x1, y1, x2, y2] : query) {
		ans = 0;

		for(; x1 <= x2; x1++) {
			ans += table[x1][y2];
			ans -= table[x1][y1 - 1];
		}

		cout << ans << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}