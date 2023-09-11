#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

bool board[100][100];

void input() {
	int tc, ldx, ldy;
	cin >> tc;
	while (tc--) {
		cin >> ldx >> ldy;
		for (int dy = 0; dy < 10; dy++) {
			for (int dx = 0; dx < 10; dx++) {
				board[ldy + dy][ldx + dx] = true;
			}
		}
	}
}

void sol() {
	int total = 0;
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if (board[y][x]) {
				total++;
			}
		}
	}
	cout << total;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}