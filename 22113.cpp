#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> bus;
vector<vector<int>> trans_table;

void input() {
	cin >> n >> m;
	bus.resize(m); trans_table.resize(n);

	for(int& b : bus) cin >> b;

	for(auto& row : trans_table) {
		row.resize(n);
		for(int& cost : row) cin >> cost;
	}
}

void sol() {
	int ans = 0;
	for(int i = 1; i < m; i++) {
		ans += trans_table[bus[i-1]-1][bus[i]-1];
	}
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}