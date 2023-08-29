#include <bits/stdc++.h>
using namespace std;

int player[5][5], judge[25];
map<int, int> player_idx;

void input() {
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			cin >> player[y][x];
			player_idx[player[y][x]] = y * 5 + x + 1;
		}
	}

	for (int i = 0; i < 25; i++) {
		cin >> judge[i];
	}
}

int check_bingo_count() {
	int test_board[5][5];
	int cnt = 0;
	int len;

	// 복사
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			test_board[y][x] = player[y][x];
		}
	}

	// 대각 검사
	if (test_board[2][2] == -1) {
		// 좌상 > 우하
		for (len = 0; len < 5; len++) {
			if (test_board[len][len] != -1) {
				break;
			}
		}
		if (len == 5) cnt++;

		// 우상 > 좌하
		for (len = 0; len < 5; len++) {
			if (test_board[len][4 - len] != -1) {
				break;
			}
		}
		if (len == 5) cnt++;
	}

	// 가로세로 검사
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			if (test_board[y][x] != -1) {
				continue;
			}
			
			// 가로 검사
			for (len = 0; len < 5; len++) {
				if (test_board[y][len] > 0) {
					break;
				}
			}
			
			// 빙고인 경우
			if (len == 5) {
				cnt++;
				for (len = 0; len < 5; len++) {
					test_board[y][len] = 0;
				}
			}

			// 세로 검사
			for (len = 0; len < 5; len++) {
				if (test_board[len][x] > 0) {
					break;
				}
			}
			// 빙고인 경우
			if (len == 5) {
				cnt++;
				for (len = 0; len < 5; len++) {
					test_board[len][x] = 0;
				}
			}
		}
	}
	return cnt;
}

void sol() {
	int cnt = 0;
	for (int jud : judge) {
		cnt++;
		int idx =  player_idx[jud] - 1;
		if (idx == -1) continue;

		int y = idx / 5;
		int x = idx % 5;
		
		player[y][x] = -1;
		if (check_bingo_count() >= 3) {
			cout << cnt;
			return;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}