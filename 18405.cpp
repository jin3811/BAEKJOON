#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n, k, s, target_x, target_y, zero;
vector<vector<int>> board;

void input() {
	cin >> n >> k;
	board.resize(n);
	for (auto& cy : board) {
		cy.resize(n);
		for (int& c : cy) {
			cin >> c;
			if (!c) zero++;
		}
	}
	cin >> s >> target_y >> target_x;
	target_x--, target_y--;
}

void sol() {
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};
	
	// 바이러스간의 우선순위가 존재하기 때문에 pq 사용
	priority_queue<tuple<int,int,int>> pq; 

	// s초동안 전염되지만, 전염될 공간이 없으면 그전에 끝내도 된다.
	for(int i = 0; i < s && zero > 0; i++) {
		// 바이러스들을 모두 찾는다.
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (board[y][x]) {
					pq.push({-board[y][x], x, y});
				}
			}
		}

		// 바이러스를 전염시킨다.
		while(!pq.empty()) {
			auto [virus, x, y] = pq.top();
			pq.pop();

			for (int d = 0; d < 4; d++) {
				int new_x = x + dx[d];
				int new_y = y + dy[d];

				if (new_x < 0 || new_x >= n || 
					new_y < 0 || new_y >= n ||
					board[new_y][new_x] != 0) continue;

				board[new_y][new_x] = -virus;
				zero--;
			}
		}
	}
	cout << board[target_y][target_x];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}