#include <bits/stdc++.h>
using namespace std;

int n, m, low, high;
vector<vector<int>> rokaf;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void input() {
	cin >> n >> m;
	rokaf.resize(n, vector<int>(m));
	for(auto& row : rokaf) {
		for(int& lev : row) {
			cin >> lev;
			high = max(high, lev);
		}
	}
	low = rokaf[0][0];
}

bool bfs(int level) {
	queue<tuple<int,int,bool>> q;
	bool visited[n][m][2]{};

	visited[0][0][0] = true;
	q.push({0, 0, false});

	while(!q.empty()) {
		auto [cur_row, cur_col, used] = q.front(); q.pop();

		if (cur_row == n - 1 && cur_col == m - 1) {
			return true;
		}

		for(int d = 0; d < 4; d++) {
			int nxt_row = cur_row + dy[d];
			int nxt_col = cur_col + dx[d];

			if (nxt_row < 0 || nxt_row >= n ||
				nxt_col < 0 || nxt_col >= m ||
				visited[nxt_row][nxt_col][used] ||
				rokaf[nxt_row][nxt_col] > level) {
				continue;
			}
			visited[nxt_row][nxt_col][used] = true;
			q.push({nxt_row, nxt_col, used});
		}

		for(int d = 0; !used && d < 4; d++) {
			int nxt_row = cur_row + dy[d];
			int nxt_col = cur_col + dx[d];

			if (nxt_row < 0 || nxt_row >= n ||
				nxt_col < 0 || nxt_col >= m ||
				rokaf[nxt_row][nxt_col] <= level) {
				continue;
			}

			nxt_row += dy[d], nxt_col += dx[d];

			if (nxt_row < 0 || nxt_row >= n ||
				nxt_col < 0 || nxt_col >= m ||
				visited[nxt_row][nxt_col][1] ||
				rokaf[nxt_row][nxt_col] > level) {
				continue;
			}

			visited[nxt_row][nxt_col][1] = true;
			q.push({nxt_row, nxt_col, true});
		}
	}

	return false;
}

void sol() {
	int mid;
	while(low <= high) {
		mid = (low + high) / 2;
		if (bfs(mid)) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << low;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}