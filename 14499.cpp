#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Dice {
	int number[4][3] = {
		{-1, 0, -1}, //    북
		{ 0, 0, 0 }, // 서 상 동
		{-1, 0, -1}, //    남 
		{-1, 0, -1}, //    하
	};

	int& get_under_num() {
		return number[3][1];
	}

	int& get_top_num() {
		return number[1][1];
	}

	void role_dice(int dir) {
		if (dir == 3) { // 북쪽 회전
			for (int i = 1; i < 4; i++) {
				swap(number[i - 1][1], number[i][1]);
			}
		}
		else if (dir == 4) { // 남쪽 회전
			for (int i = 3; i > 0; i--) {
				swap(number[i][1], number[i - 1][1]);
			}
		}
		else if (dir == 1) { // 동쪽 회전
			rotate(number[1], number[1] + 2, number[1] + 3);
			swap(number[1][0], number[3][1]);
		}
		else if (dir == 2) { // 서쪽 회전
			rotate(number[1], number[1] + 1, number[1] + 3);
			swap(number[1][2], number[3][1]);
		}
		else assert(false);
	}
	
	// void show_dice() {
	// 	for(int y = 0; y < 4; y++) {
	// 		for(int x = 0; x < 3; x++) {
	// 			if (number[y][x] == -1) cout << "  ";
	// 			else cout << number[y][x] << ' ';
	// 		}
	// 		cout << endl;
	// 	}
	// }
};

int n, m, sx, sy, k;
vector<vector<int>> board;
vector<int> query;

void input() {
	cin >> n >> m >> sy >> sx >> k;
	board.resize(n, vector<int>(m));
	query.resize(k);
	for(auto& row : board) {
		for(int& c : row) {
			cin >> c;
		}
	}
	for(int& q : query) cin >> q;
}

void sol() {
	Dice d;
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	int nx, ny;

	for(const int& q : query) {
		nx = sx + dx[q - 1], ny = sy + dy[q - 1];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
			continue;
		}

		sx = nx, sy = ny;
		d.role_dice(q);

		if (board[sy][sx]) { // 양수가 적혀있으면 주사위로 옮김
			int val = board[sy][sx];
			d.get_under_num() = val;
			board[sy][sx] = 0;
		}
		else { // 0이 적혀있다면 칸으로 복사
			int val = d.get_under_num();
			board[sy][sx] = val;
		}

		cout << d.get_top_num() << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}