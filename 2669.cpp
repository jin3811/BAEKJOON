#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int ldx, ldy, rux, ruy;
int board[100][100];

void draw() {
	for(int y = ldy; y < ruy; y++) {
		for (int x = ldx; x < rux; x++) {
			board[y][x] = 1;
		}
	}
}

void input() {
	for (int i = 0; i < 4; i++) {
		cin >> ldx >> ldy >> rux >> ruy;
		draw();
	}
}

void sol() {
	int cnt = 0;
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if (board[y][x] == 1) {
				cnt++;
			}
		}
	}
	cout << cnt;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}