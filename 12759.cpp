#include <bits/stdc++.h>
using namespace std;

int board[4][4];

bool is_end() {
	bool res;

	// 가로 체크
	for (int y = 1; y <= 3; y++) {
		res = true;
		for (int x = 1; x < 3; x++) {
			if (!board[y][x] || !board[y][x + 1]) res = false;
			res = res && board[y][x] == board[y][x + 1];
		}
		if (res) return res;
	}

	// 세로 체크
	for (int x = 1; x <= 3; x++) {
		res = true;
		for (int y = 1; y < 3; y++) {
			if (!board[y][x] || !board[y + 1][x]) res = false;
			res = res && board[y][x] == board[y + 1][x];
		}
		if (res) return res;
	}

	// -1 대각선 체크
	res = true;
	for (int i = 1; i < 3; i++) {
		if (!board[i][i] || !board[i + 1][i + 1]) res = false;
		res = res && board[i][i] == board[i + 1][i + 1];
	}
	if (res) return res;

	// 1 대각선 체크
	res = true;
	for (int i = 1; i < 3; i++) {
		if (!board[i][4 - i] || !board[i + 1][3 - i]) res = false;
		res = res && board[i][4 - i] == board[i + 1][3 - i];
	}
	if (res) return res;

	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int cur, x, y, lim = 9;

	cin >> cur;
	while(lim--) {
		cin >> y >> x;
		board[y][x] = cur;
		if (is_end()) {
			cout << cur;
			exit(0);
		}
        cur = cur == 1 ? 2 : 1;
	}
	cout << 0;
}