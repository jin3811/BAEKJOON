#include <bits/stdc++.h>
using namespace std;

int r, c;
vector<string> grass;

void input() {
	cin >> r >> c;
	grass.resize(r);
	for(auto& g : grass) cin >> g;
}

void bfs(int st_x, int st_y) {
	queue<pair<int,int>> q;
	int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

	q.push({st_x, st_y});
	grass[st_y][st_x] = '.';

	while(!q.empty()) {
		auto [cur_x, cur_y] = q.front();
		q.pop();

		for(int d = 0; d < 4; d++) {
			int nxt_x = cur_x + dx[d], nxt_y = cur_y + dy[d];

			if (nxt_x < 0 || nxt_x >= c ||
				nxt_y < 0 || nxt_y >= r ||
				grass[nxt_y][nxt_x] == '.') continue;

			q.push({nxt_x, nxt_y});
			grass[nxt_y][nxt_x] = '.';
		}
	}
}

void sol() {
	int ans = 0;
	for(int y = 0; y < r; y++) {
		for(int x = 0; x < c; x++) {
			if (grass[y][x] != '.') {
				++ans;
				bfs(x, y);
			}
		}
	}
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}