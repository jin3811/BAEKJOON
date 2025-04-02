
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m, k;
int farm[2500][2500];

void input() {
	memset(farm, 0, sizeof(int)*2500*2500);
	int r, c;
	cin >> m >> n >> k;
	while(k--) {
		cin >> c >> r;
		farm[r][c] = 1;
	}
}

void bfs(int r, int c) {
	int dr[]{0, 1, 0, -1}, dc[]{1, 0, -1, 0};
	queue<pair<int,int>> q;

	farm[r][c] = 0;
	q.push({r, c});

	while(!q.empty()) {
		auto [cr, cc] = q.front(); q.pop();

		for(int d = 0; d < 4; d++) {
			int nr = cr+dr[d], nc = cc+dc[d];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m || !farm[nr][nc]) {
				continue;
			}

			farm[nr][nc] = 0;
			q.push({nr, nc});
		}
	}
}

void sol() {
	int ans = 0;
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < m; c++) {
			if (farm[r][c]) {
				++ans;
				bfs(r, c);
			}
		}
	}
	cout << ans << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		input();
		sol();
	}
}