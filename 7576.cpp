#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int>> tomato;
queue<tuple<int,int,int>> q;

void input() {
	cin >> m >> n;
	tomato.resize(n, vector<int>(m));

	for(int r = 0; r < n; r++) {
		for(int c = 0; c < m; c++) {
			cin >> tomato[r][c];
			if (tomato[r][c] == 1) {
				q.emplace(0, r, c);
				tomato[r][c] = -1;
			}
		}
	}
}

void bfs() {
	int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

	while(!q.empty()) {
		auto [day, cr, cc] = q.front(); q.pop();

		for(int d = 0; d < 4; d++) {
			int nr = cr + dy[d], nc = cc + dx[d];

			if (nr < 0 || nr >= n || nc < 0 || nc >= m || tomato[nr][nc] == -1) {
				continue;
			}

			if (tomato[nr][nc] == 0 || tomato[nr][nc] > day + 1) {
				tomato[nr][nc] = day + 1;
				q.emplace(day + 1, nr, nc);
			}
		}
	}
}

void sol() {
	int ans = 0;

	bfs();
	for(auto& row : tomato) {
		for(int& t : row) {
			if (!t) {
				cout << -1;
				return;
			}
			ans = max(ans, t);
		}
	}
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}