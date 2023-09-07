#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n;
int st_x, st_y, ed_x, ed_y;
vector<vector<int>> chess;

void input() {
	cin >> n;
	chess.clear();
	chess.resize(n);
	for (auto& line : chess) {
		line.resize(n);
	}
	cin >> st_x >> st_y >> ed_x >> ed_y;
}

void sol() {
	int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	queue<tuple<int, int, int>> q;
	
	q.push({st_x, st_y, 0});
	chess[st_y][st_x] = -1;

	while (!q.empty()) {
		auto[cur_x, cur_y, dist] = q.front();
		q.pop();

		// 종료 조건
		if (cur_x == ed_x && cur_y == ed_y) {
			cout << dist << endl;
			return;
		}

		for (int i = 0; i < 8; i++) {
			int nxt_x = cur_x + dx[i];
			int nxt_y = cur_y + dy[i];			
		 	
			if (nxt_x < 0 || nxt_x >= n ||
				nxt_y < 0 || nxt_y >= n ||
				chess[nxt_y][nxt_x] == -1) {
				continue;
			}

			q.push({nxt_x, nxt_y, dist + 1});
			chess[nxt_y][nxt_x] = -1;			
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		input();
		sol();
	}
}