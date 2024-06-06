#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using pii = pair<int, int>;

int n, m;
vector<vector<int>> board;
pii goal;

void input() {
	int road;
	cin >> n >> m;
	board.resize(n);

	for(int y = 0; y < n; y++) {
		board[y].resize(m);

		for(int x = 0; x < m; x++) {
			cin >> road;
			if (road == 2) {
				goal.first = x;
				goal.second = y;
			}
			if (road > 0) {
				board[y][x] = -1;
			}
		}
	}
}

void sol() {
	queue<pii> q;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};

	q.push(goal);
	board[goal.second][goal.first] = 0;

	while (!q.empty()) {
		auto [curX, curY] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newX = curX + dx[i];
			int newY = curY + dy[i];
			if (newX < 0 || newX >= m || // x축 범위 밖
				newY < 0 || newY >= n || // y축 범위 밖
				board[newY][newX] >= 0) continue; // 이미 방문한 곳
			
			board[newY][newX] = board[curY][curX] + 1;
			q.push({newX, newY});
		}
	}
	for(auto& row : board) {
		for (int& x : row) cout << x << ' ';
		cout << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	sol();
}